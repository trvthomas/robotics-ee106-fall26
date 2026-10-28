# Lab 3
Open loop control

[Link to lab](https://ucr-ee106.readthedocs.io/en/latest/lab3.html)

---

### Notes

Open loop control. Moving the robot in a square using **linear velocity in the x direction** to make it move *forward* and **angular velocity in the z direction** to make it *turn left.*

`open_loop.py` act as a publisher Node to the `cmd_vel` topic, posting the twist vector/object that I assume is received by other Nodes, processed, and converted into actions.