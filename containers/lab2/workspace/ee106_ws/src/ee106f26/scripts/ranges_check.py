#!/usr/bin/env python3

import math, numpy

import numpy as np
import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from rclpy.time import Time
from sensor_msgs.msg import LaserScan
from std_msgs.msg import String
from tf2_ros import TransformException
from tf2_ros.buffer import Buffer
from tf2_ros.transform_listener import TransformListener

from std_msgs.msg import String

from tf_transformations import quaternion_matrix

class Lab2TemplateNode(Node):

    def __init__(self):
        super().__init__('ranges_check')
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        self.pub = self.create_publisher(String, 'turtlebot_status', 5)
        
        self.sub = self.create_subscription(LaserScan, 'scan', self.callback, 5)
        

    def callback(self, scan: LaserScan):
        # Get the transformations and rotations
        try:
            t = self.tf_buffer.lookup_transform(
                'turtlebot4/rplidar_link/rplidar', 'base_link', Time()
            )
        except TransformException:
            self.get_logger().warn('TF not available yet')
            return

        trans = t.transform.translation
        rot = t.transform.rotation

        # Build a 4x4 homogeneous transform matrix T
        T = quaternion_matrix([rot.x, rot.y, rot.z, rot.w])
        T[0:3, 3] = [trans.x, trans.y, trans.z]

        # Loop over all ranges, skip the inf ranges
        worst = 'minor'
        for idx, r in enumerate(scan.ranges):
            if not np.isfinite(r):
                continue

            # transform each point; convert from polar to cartesian
            theta = scan.angle_min + idx * scan.angle_increment
            x_l = r * math.cos(theta)
            y_l = r * math.sin(theta)
            p_l = numpy.array([x_l, y_l, 0, 1]) # Point from Lidar with respect to Lidar's frame

            # transform into base_link frame
            p_b = T @ p_l # Point from Lidar with respect to robot's base_link frame

            # compute distance (in meters)
            dist = math.hypot(p_b[0], p_b[1])

            if dist < 0.2:
                worst = "critical"
            if dist < 0.5 and worst != "critical":
                worst = "major"

        # PUBLISH worst
        msg = String()
        msg.data = worst

        self.pub.publish(msg)
        
        log = f"Publishing msg distance: {msg.data}"
        self.get_logger().info(log)


def main(args=None):
    rclpy.init(args=args)

    node = Lab2TemplateNode()

    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()