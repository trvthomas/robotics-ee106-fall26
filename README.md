# Programming Practical Robots

## General Concepts

### Frames :framed_picture:

A frame is a reference coordinate system used to measure and describe where things are (position) and in whichd direction they are facing (orientation).\
Without a frame, a coordinate like (x, y, z) is useless because we haven't defined where our "zero" or "base" is. With a frame we can then define which way is up/down/left/right.

#### How are frames represented?

In a robot, frames are a fixed physical reference point. For example, the center of a robot's wheel, the LiDAR sensor.\
Mathematically, frames are defined relative to one another based on its **pose** (position and orientation).

**Reference concepts used in the following definitions:**
- **R<sub>AB</sub>**: Rotation matrix of frame {B} with respect to frame {A}
- **T<sub>AB</sub>**: Transformation matrix of frame {B} with respect to frame {A}
- **{A}** is the *reference frame (fixed frame)*
- **{B}** is the *body frame*

### Position and Rotation :face_with_spiral_eyes:

#### Position

Answers the question: *Where is the object located in space?*

```math
p = \begin{bmatrix}
    p_x\\
    p_y\\
    p_z
\end{bmatrix}_{3x1}
```

It's a 3x1 translation vector: line segment *starting at the origin of a reference frame **{A}*** and *pointing towards a specific point in another frame **{B}***.\

#### Rotations

Answers the question: *Which direction is the object pointing?*

```math
R = \begin{bmatrix}
    \vdots & \vdots & \vdots\\
    x_b & y_b & z_b \\
    \vdots & \vdots & \vdots
\end{bmatrix}_{3x3}
```
It's a 3x3 matrix whose columns are the unit vectors of the frame **{B}** projected onto frame **{A}**.\
Captures the orientation of a rigid body relative to a reference frame, ignoring it's location in space.\
> [!TIP]
>**:baby: In kids terms:** If we want to find R<sub>AB</sub> (rotation matrix of B with respect to A), we take frame **{B}** and put it on top of **{A}**, then check the coordinates of **B** WITH RESPECT TO **A**.\
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

#### Fixed and Body Rotations

To rotate a frame about some other axis we multiply the **rotation matrix** of the **current frame (new)** * the rotation matrix of the **other frame (old)**. We multiply on the left or right repending on whether we want to do a rotation with respect to the new or old.

##### Fixed Frame (left)

```math
R = rot(x, 90)\\
R_{AB} = R*R_{AB}
```
> [!TIP]
>**:baby: In kids terms:** Visually. We have frame {A} and frame {B}, and we want to do a $`rot(x, 90)`$, **x with respect to frame *A*.** So we take frame {B} and rotate it 90 degrees with x-axis of frame {A} as our "fixed"/reference axis.


##### Body Frame (right)

```math
R = rot(x, 90)\\
R_{AB} = R_{AB}*R
```
> [!TIP]
>**:baby: In kids terms:** Visually. We have frame {A} and frame {B}, and we want to do a $`rot(x, 90)`$, **x with respect to frame *B*.** So we take frame {B} and rotate it 90 degrees with x-axis of frame {B} as our "fixed"/reference axis.

### Transformations :dizzy:

Answers the question: *Where is the object and which way is it facing?*

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

#### Point Transformation

> [!TIP]
>**:baby: In kids terms:** We have a point $`p_a = \begin{bmatrix}
    x\\
    y\\
    z
\end{bmatrix}`$. That vector shows how to get to that point if we have the origin at frame {a}. **What if we want to express how to get to that point but if we start in another frame {s} origin?** We use:

```math
\begin{bmatrix}
    p_s\\
    1
\end{bmatrix}
= T_{sa} \begin{bmatrix}
    p_a\\
    1
\end{bmatrix}
```

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

### Pending, more terms?

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

#### Skew-Symmetric Matrix
A matrix whose transpose is equal to its negative

```math
[\omega] = \begin{bmatrix}
    0 & -\omega_z & \omega_y\\
    \omega_z & 0 & -\omega_x\\
    -\omega_y & \omega_x & 0
\end{bmatrix}
```

```math
[\omega] = -[\omega]^T
```

#### Rate of change

Find the rate of change of a rotation ($`\dot{R}`$) having the angular velocity ($`\omega`$)

```math
\dot{R_{AB}} = [\omega]R_{AB}
```

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

## Wheeled Robot Kinematics

### Omni-directional robots

- Can move in any direction in 2D space (forward, backward, sideways), don't need to "turn" to move in a new direction

### Non-holonomic robots

- Cannot generate velocity in a certain direction
    - ex. can move forward and backward. I order to move "sideways" it needs to turn x degrees and then move forward

Since these robots work in **2D space**, we have a special case of 3x3 transformation matrix, used **only in pen and paper math,** when coding, for simplicity, we want to use the 4x4 matrix.

```math
T = \begin{bmatrix}
    \cos(\phi) & -\sin(\phi) & \cancel{0} & p_x\\
    \sin(\phi) & \cos(\phi) & \cancel{0} & p_y\\
    \cancel{0} & \cancel{0} & \cancel{1} & \cancel{0}\\
    0 & 0 & \cancel{0} & 1
\end{bmatrix}
= \begin{bmatrix}
    \cos(\phi) & -\sin(\phi) & p_x\\
    \sin(\phi) & \cos(\phi) & p_y\\
    0 & 0 & 1
\end{bmatrix}
```

In the same way, twist can be simplified, since we are not using the z component in linear velocity nor the xy components in angular velocity.

```math
V_b = \begin{bmatrix}
    \omega_{v,z} & v_{b,x} & v_{b,y}
\end{bmatrix}
```

```math
V = \begin{bmatrix}
    0\\
    0\\
    \omega_z\\
    v_x\\
    v_y\\
    0
\end{bmatrix}
```

#### Sub-types

##### Unicycle
- Imagine a wheel
- Configuration: $`q=\begin{bmatrix}
    \phi & x & y
\end{bmatrix}^T`$
- Wheel radius: $`r`$
- Kinematic model $`\dot{q}=f(q, u)`$:

```math
\dot{q} = \begin{bmatrix}
    \dot{\phi}\\
    \dot{x}\\
    \dot{y}
\end{bmatrix}
= \begin{bmatrix}
    0 & 1\\
    r\cos(\phi) & 0\\
    r\sin(\phi) & 0
\end{bmatrix}
\begin{bmatrix}
    u_1\\
    u_2
\end{bmatrix}
```

$`u_1`$ = rate of change of steering angle
$`u_2`$ = angular velocity of the wheel

Multiplying out each row from the matrix we can get the individual components:

**Heading/Yaw rate ($`\dot{\psi}`$**)

```math
\omega = \dot{\psi} = u_2
```

**Inertial x velocity ($`\dot{x}`$**)

```math
\dot{x} = v\cos(\phi)
```

**Inertial y velocity ($`\dot{y}`$**)

```math
\dot{y} = v\sin(\phi)
```

**Where did the linear velocity ($`v`$?) came from?**\\
From the matrix we simplified the linear velocity ($`v`$?):

```math
v = ru_1
```

##### Differential drive
- Configuration: $`q=\begin{bmatrix}
    \phi & x & y
\end{bmatrix}^T`$
- Offset distance: $`d`$
- Kinematic model $`\dot{q}=f(q, u)`$:

```math
\dot{q} = \begin{bmatrix}
    \dot{\phi}\\
    \dot{x}\\
    \dot{y}
\end{bmatrix}
= \begin{bmatrix}
    \frac{-r}{2d} & \frac{r}{2d}\\
    \frac{r}{2}\cos{\phi} & \frac{r}{2}\cos{\phi}\\
    \frac{r}{2}\sin{\phi} & \frac{r}{2}\sin{\phi}
\end{bmatrix}
\begin{bmatrix}
    u_L\\
    u_R
\end{bmatrix}
```

$`u_L`$ = angular velocity of left wheel
$`u_R`$ = angular velocity of right wheel

Multiplying out each row from the matrix we can get the individual components:

**Angular velocity ($`\omega`$**)

```math
\omega = \frac{r}{2d}(u_R-u_L)
```

**Inertial x velocity ($`\dot{x}`$**)

```math
\dot{x} = v\cos(\phi)
```

**Inertial y velocity ($`\dot{y}`$**)

```math
\dot{y} = v\sin(\phi)
```

**Where did the linear velocity ($`v`$?) came from?**\\
From the matrix we simplified the linear velocity ($`v`$?):

```math
v = \frac{r}{2}(u_L+u_R)
```

##### Car-like
- Configuration: $`q=\begin{bmatrix}
    \phi & x & y & \theta
\end{bmatrix}^T`$
- Offset distance: $`d`$
- Kinematic model $`\dot{q}=f(q, u)`$:

```math
\dot{q} = \begin{bmatrix}
    \dot{\phi}\\
    \dot{x}\\
    \dot{y}\\
    \dot{\psi}
\end{bmatrix}
= \begin{bmatrix}
    \frac{\tan{\psi}}{l} & 0\\
    \cos{\phi} & 0\\
    \sin{\phi} & 0\\
    0 & 1\\
\end{bmatrix}
\begin{bmatrix}
    v\\
    \omega
\end{bmatrix}
```

$`v`$ = linear forward speed
$`\omega`$ = angular speed of the steering angle

<!-- ### Degrees of Freedom (DoF)
Minimum number of constraints needed to complete a configuration

### Kinematic Constraints
Holonomic vs no holonomic
differential drive kinematics
-->