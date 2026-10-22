# Programming Practical Robots

## General Concepts

### Frames :framed_picture:

#### What is a frame?

A frame is a reference coordinate system used to measure and describe where things are (position) and in whichd direction they are facing (orientation).\
Without a frame, a coordinate like (x, y, z) is useless because we haven't defined where our "zero" or "base" is. With a frame we can then define which way is up/down/left/right.

#### How are frames represented?

In a robot, frames are a fixed physical reference point. For example, the center of a robot's wheel, the LiDAR sensor.\
Mathematically, frames are defined relative to one another based on its **pose** (position and orientation).

**Reference concepts used in the following definitions:**
- **R<sub>AB</sub>**: Rotation matrix of B with respect to A
- **T<sub>AB</sub>**: Transformation matrix of B with respect to B
- **{A}** is the *reference frame (fixed frame)*
- **{B}** is the *body frame*

##### Position vector
*Where is the object located in space?*
```math
p = \begin{bmatrix}
    p_x\\
    p_y\\
    p_z
\end{bmatrix}_{3x1}
```

It's a 3x1 translation vector: line segment *starting at the origin of a reference frame **{A}*** and *pointing towards a specific point in another frame **{B}***.\

##### Rotation matrix
*Which direction is the object pointing?*
```math
R = \begin{bmatrix}
    : & : & :\\
    x_b & y_b & z_b \\
    : & : & :
\end{bmatrix}_{3x3}
```
It's a 3x3 matrix whose columns are the unit vectors of the frame **{B}** projected onto frame **{A}**.\
Captures the orientation of a rigid body relative to a reference frame, ignoring it's location in space.\
**In kids terms:**If we want to find R<sub>AB</sub> (rotation matrix of B with respect to A), we take frame **{B}** and put it on top of **{A}**, then check the coordinates of **B** WITH RESPECT TO **A**.\
ex.
```
{A}        {B}
  y         z
  |__ x     |__y
 /         /
z         x
```
```math
R_{AB} = \begin{bmatrix}
    0 & 1 & 0\\
    0 & 0 & 1 \\
    1 & 0 & 0
\end{bmatrix}
```

##### Transformation matrix
*Where is the object and which way is it facing?*
```math
T = \begin{bmatrix}
    R & p\\
    0 & 1
\end{bmatrix}
= \begin{bmatrix}
    r_{11} & r_{12} & r_{13} & p_x\\
    r_{21} & r_{22} & r_{23} & p_y\\
    r_{31} & r_{32} & r_{33} & p_z\\
    0 & 0 & 0 & 1\\
\end{bmatrix}_{4x4}
```

It's a 4x4 matrix that combines both the **position vector** and the **orientation matrix**. Represents the pose of a rigid body.

#### Mathematical properties

There are 2 main useful properties:

##### Chain rule
$`T_{AD} = T_{A\cancel{B}} * T_{\cancel{B}\cancel{C}} * T_{\cancel{C}D}`$\
We can cancel out the inner adjacent frames :grin:

##### Inverse transformation
$`R_{BA} = R^{-1}_{AB} = R^{T}_{AB}`$\
We can take the inverse/transpose of a rotation matrix to get the opposite frame configurations, for transformations it works differently:
```math
M_{BA} = T^{-1}_{AB} = \begin{bmatrix}
    R^{T}_{AB} & -R^{T}_{AB}*p\\
    0 & 1
\end{bmatrix}
```
> [!WARNING]
> It's a common mistake to just do the transpose for a transformation matrix, that is WRONG!!

#### Why are frames important?

Mainly to get the correct coordinates. Sensors are located in different positions with respect to the **base frame**. To get accurate mathematical conversions, mapping, and movement, we need to take the points gathered by the sensors and translate and rotate them so they can be processed accordingly.

#### How many frames can a robot have?

As many as needed. They are represented and organized in a hierarchical tree (TF tree). Every rigid link and sensor has its own frame (ex. base_link, shoulder, elbow, wheel_left, wheel_right, lidar, camera)

### Velocities :runner:

Position and orientation change over time. In robotics, a rigid body can move, slide, and spin. These set of movements are packed up into a 6-dimensional object called a **twist**.

#### Angular Velocity
*How fast an object is **spinning***
```math
\omega = \begin{bmatrix}
    \omega_x\\
    \omega_y\\
    \omega_z
\end{bmatrix}
```

Represent the **speed and axis** of rotation.\
Magnitude ($`||\omega||`$) represents the **spin speed**.

#### Linear Velocity
*How fast a point is **translating***
```math
v = \begin{bmatrix}
    v_x\\
    v_y\\
    v_z
\end{bmatrix}
```

Represent the **speed and direction** of a straight-line movement.

#### Twist

It merges both angular and linear velocities.
```math
V = \begin{bmatrix}
    \omega\\
    v
\end{bmatrix}
= \begin{bmatrix}
    \omega_x\\
    \omega_y\\
    \omega_z\\
    v_x\\
    v_y\\
    v_z
\end{bmatrix}
```