#!/usr/bin/env python3
from math import pi, sqrt, atan2, cos, sin
import numpy as np
import time, rclpy, threading
from tf_transformations import euler_from_quaternion
from rclpy.node import Node
from nav_msgs.msg import Odometry
from geometry_msgs.msg import TwistStamped, Pose2D
from class_controller import Controller

class Turtlebot(Node): # original: no Node attribute
    def __init__(self):
        super().__init__('turtlebot_move')

        self.get_logger().info("Press Ctrl + C to terminate")

        # Create publisher for publishing the velocity commands
        self.vel_pub = self.create_publisher(TwistStamped, "cmd_vel", 10)
        self.pose = Pose2D()
        self.logging_counter = 0
        self.trajectory = list()
        self.odom_sub = self.create_subscription(Odometry, "odom", self.odom_callback, 10)

    def run(self):
        """
        Run function. There are a variety of design patterns.
        An alternative would have been to use the `timer_callback`
        design pattern shown in previous labs.
        """

        self.get_logger().info('Running closed-loop control...')

        move_forward(self, 4, 0, 1)
        turn_left(self, ((pi/2)+0.02))
        move_forward(self, 4, 4, 3)
        turn_left(self, (pi))
        move_forward(self, 0, 4, 5)
        turn_left(self, ((-pi/2)-0.08))
        move_forward(self, 0, 0, 7)

    def odom_callback(self, msg):
        # get pose = (x, y, theta) from odometry topic
        quarternion = [msg.pose.pose.orientation.x, msg.pose.pose.orientation.y, msg.pose.pose.orientation.z, msg.pose.pose.orientation.w]
        
        (roll, pitch, yaw) = euler_from_quaternion(quarternion)
        
        self.pose.theta = yaw
        self.pose.x = msg.pose.pose.position.x
        self.pose.y = msg.pose.pose.position.y

        # logging once every 6 times (Gazebo runs at 60Hz; we save it at 10Hz)
        self.logging_counter += 1
        if self.logging_counter == 6:
            self.logging_counter = 0
            self.trajectory.append([self.pose.x, self.pose.y])  # save trajectory
            # display (x, y, theta) on the terminal
            self.get_logger().info("odom: x=" + str(self.pose.x) + ";  y=" + str(self.pose.y) + ";  theta=" + str(yaw))

def move_forward(self, desiredX, desiredY, step):
    log(self, "CONTROLLER: Move forward")
    vel = TwistStamped()

    # Activate the controller(self, Kp, Kd, reference_point)
    controller = Controller(1.5, 0.7, desiredX)
    #controllerAngle = Controller(2.0, 0.5, 0)

    #correctAngleCount = 0

    measured = self.pose.x if step == 1 or step == 5 else self.pose.y

    #while (sqrt(((desiredX - self.pose.x) ** 2) + ((desiredY - self.pose.y) ** 2))) > 0.08:
    while (abs(desiredX - measured)) > 0.05:
        if step == 1 or step == 5:
            correctedLinearVel = controller.update(self.pose.x)
        else:
            correctedLinearVel = controller.update(self.pose.y)

        """
        correctAngleCount = correctAngleCount + 1
        correctedAngularVel = 0.0

        if correctAngleCount > 5:
            desired_theta = atan2((desiredY - self.pose.y), (desiredX - self.pose.x))
            angle_error = atan2(sin(desired_theta - self.pose.theta), cos(desired_theta - self.pose.theta))
            correctedAngularVel = controllerAngle.update(angle_error) * 14

            correctAngleCount = 0
            self.get_logger().info(f"AAAANNGGLE {correctedAngularVel}")
        """
        
        if step == 5 or step == 7:
            correctedLinearVel = correctedLinearVel * -1

        measured = self.pose.x if step == 1 or step == 5 else self.pose.y

        vel.twist.linear.x = correctedLinearVel
        vel.twist.angular.z = 0.0
        self.vel_pub.publish(vel)
        time.sleep(0.1)

    stop(self)

def turn_left(self, desiredAngle):
    log(self, "CONTROLLER: Turn left")
    vel = TwistStamped()
    vel.twist.linear.x = 0.0

    # Activate the controller(self, Kp, Kd, reference_point)
    controller = Controller(1.5, 0.2, desiredAngle)

    while (abs(desiredAngle - self.pose.theta)) > 0.01:
        correctedAngularVel = controller.update(self.pose.theta)

        vel.twist.angular.z = correctedAngularVel
        self.vel_pub.publish(vel)
        time.sleep(0.1)

    stop(self)

def stop(self):
    log(self, "STOP")
    vel = TwistStamped()
    vel.twist.linear.x = 0.0
    vel.twist.angular.z = 0.0

    self.vel_pub.publish(vel)
    time.sleep(1)

def log(self, msg):
    self.get_logger().info('========================')
    self.get_logger().info('========================')
    self.get_logger().info('========================')
    self.get_logger().info(msg)

def main(args=None):
    """
    Entry point function for the Open Loop control node.

    @param args - Arguments that need to be passed to ROS.
    """

    # Initialize the client library - this is required
    rclpy.init(args=args)

    # Create the publisher node
    turtlebot_node = Turtlebot()

    # Spin so that the node is busy processing
    # while no exceptions are encountered and ROS
    # is executing
    # For this lab - spin rclpy on separate thread
    thread = threading.Thread(target=rclpy.spin, args=(turtlebot_node,), daemon=True)
    thread.start()

    # Allow time for other nodes to start
    time.sleep(5)

    try:
        turtlebot_node.run()
    except KeyboardInterrupt:
        pass
    finally:
        # save trajectory into csv file
        np.savetxt('trajectory.csv', np.array(turtlebot_node.trajectory), fmt='%f', delimiter=',')

        # Destroy the node explicitly
        turtlebot_node.destroy_node()

        # Shut down this context
        rclpy.shutdown()

if __name__ == '__main__':
    main()