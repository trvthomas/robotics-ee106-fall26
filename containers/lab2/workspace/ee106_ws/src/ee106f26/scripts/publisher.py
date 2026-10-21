#!/usr/bin/env python3

import rclpy, random
from rclpy.node import Node

from ee106f26.msg import EE106LabCustomNew

class Publisher(Node):
    def __init__(self):
        super().__init__('talker')

        self.publisher_ = self.create_publisher(EE106LabCustomNew, 'EE106lab_topic', 5)

        timer_period = 6  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def timer_callback(self):
        rand = EE106LabCustomNew()
        rand.int_data1 = random.randint(0, 100)
        rand.int_data2 = random.randint(101, 200)

        self.publisher_.publish(rand)
        s = f"1#{rand.int_data1} - 2#{rand.int_data2}"
        self.get_logger().info(s)

def main(args=None):
    rclpy.init(args=args)

    publisher = Publisher()

    rclpy.spin(publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
