# Lab 1
Explore ROS2 nodes, topics, and messages; how they work, how they interact with each other, how to create them, and how to use messages to pass down information.

[Link to lab](https://ucr-ee106.readthedocs.io/en/latest/lab1.html)

---

### Notes

Creation of the package inside the ```..ee106_ws/src``` directory: ```ros2 pkg create ee106f26 --build-type ament_cmake --dependencies rclpy rclcpp std_msgs```

General commands used inside the container:

```colcon build```

```source install/setup.bash```

Execute publisher and subscriber nodes: ```ros2 run ee106f26 publisher/subscriber.py```

```ee106f26``` refers to the package we are using

Use ```rqt_graph``` to visualize all nodes and topics!