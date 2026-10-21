# Lab 2
Tools and testing with Turtlebot simulation

[Link to lab](https://ucr-ee106.readthedocs.io/en/latest/lab2.html)

---

### Notes

Launch files: ```ros2 launch <package_name> <file_name>.launch.py```

Launch Turtlebot:
- In empty world: ```ros2 launch ee106f26 turtlebot.launch.py model:=lite world:=empty```
- In maze world: ```ros2 launch ee106f26 turtlebot.launch.py model:=lite world:=maze```
- Teleop keyboard operation: ```ros2 run teleop_twist_keyboard teleop_twist_keyboard --ros-args -r cmd_vel:=/cmd_vel_unstamped```

### RVIS2:
A visual debugging tool to see the robot's frames, behavior, Lidar scans, etc.

```rviz2```

Configurations:
- *Global Options > Fixed Frame:* base_link
- *Add:* TF & LaserScan
- *LaserScan > Topic:* /scan
- *LaserScan > Size:* Custom size, recommended 0.2

### Create Frames
Create new front_bumper frame w/ respect to base_link frame: ```ros2 run tf2_ros static_transform_publisher --x 0.26 --y 0 --z 0.11 --qx 0 --qy 0 --qz 0 --qw 1 --frame-id base_link --child-frame-id front_bumper```

Obtain __transformation matrix__ between front_bumper and base_link frames: ```ros2 run tf2_ros tf2_echo base_link front_bumper``` or execute ```ros2 run ee106f26 tf_listener.py```

#### Install transforms3d library

If you get the "transforms3d library not found" error, execute the following:

```
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install python3-transforms3d
```