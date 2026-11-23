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

It's a 3x1 translation vector: line segment *starting at the origin of a reference frame **{A}*** and *pointing towards a specific point in another frame **{B}***.

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

To rotate a frame about some other axis we multiply the **rotation matrix** of the **current frame (new)** * the rotation matrix of the **other frame (old)**. We multiply on the left or right depending on whether we want to do a rotation with respect to the new or old.

##### Fixed Frame (left)

```math
R = rot(x, 90)
```
```math
R_{AB} = R*R_{AB}
```
> [!TIP]
>**:baby: In kids terms:** Visually. We have frame {A} and frame {B}, and we want to do a $`rot(x, 90)`$, **x with respect to frame *A*.** So we take frame {B} and rotate it 90 degrees with x-axis of frame {A} as our "fixed"/reference axis.


##### Body Frame (right)

```math
R = rot(x, 90)
```
```math
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
x & y & z
\end{bmatrix}^T`$. That vector shows how to get to that point if we have the origin at frame {a}. **What if we want to express how to get to that point but if we start in another frame {s} origin?** We use:

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
Magnitude ($`\| \omega \|`$) represents the **spin speed**.

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
[\omega] = -[\omega]^T
```

```math
[\omega] = \begin{bmatrix}
    0 & -\omega_z & \omega_y\\
    \omega_z & 0 & -\omega_x\\
    -\omega_y & \omega_x & 0
\end{bmatrix}
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

#### Adjoint transformation matrix

```math
[Ad_{T}] = \begin{bmatrix}
    R & 0\\
    [p]R & R
\end{bmatrix}
```

```math
[p] = \begin{bmatrix}
    0 & -p_z & p_y\\
    p_z & 0 & -p_x\\
    -p_y & p_x & 0
\end{bmatrix} \begin{bmatrix}
    \omega\\
    v
\end{bmatrix}
```

Used to change the reference frame of a twist.

#### Body and spatial twists

To understand **body** and **spatial** twists, we imagine the following scenario with 2 frames:
- We have a CD with a stick glued in the middle. In the outer edge of the CD there's a coin. We start rotating the stick so the whole thing can rotate with it.
- Frame {s} is the stick
- Frame {b} is the coin at the CD's outer edge

```math
V_b = \begin{bmatrix}
    \omega_b\\
    v_b
\end{bmatrix}
```

```math
V_s = \begin{bmatrix}
    \omega_s\\
    v_s
\end{bmatrix}
```

| Component | Body twist {b}  | Spatial twist {s} |
| --- | --- | --- |
| Axis of measurement  | $`x_b, y_b, z_b`$  | $`x_s, y_s, z_s`$ |
| What does $`v`$ represent?  | Velocity of {b}. How fast is the coin moving? It has a tangential velocity component, thus the coin may have both angular and linear velocities $`\omega, v \neq 0`$. | Velocity of {s}, which in this case is 0 because we are rotating the stick only. The stick is not moving in any other direction. |

##### Using with adjoint transformations

The $`[Ad_{T}]`$ transformation matrix can be used to change the reference frame of a twist. In other words, we want to find the body twist {b} of the coin at that moment knowing the spatial twist {s} from the stick, or viceversa.

```math
V_b = [Ad_{T_{bs}}]V_s
```

```math
V_s = [Ad_{T_{sb}}]V_b
```


## Wheeled Robot Kinematics

### Omni-directional robots :ghost:

- Can move in any direction in 2D space (forward, backward, sideways), don't need to "turn" to move in a new direction

### Non-holonomic robots :car:

- Cannot generate velocity in a certain direction
    - ex. can move forward and backward. In order to move "sideways" it needs to turn first ($`\omega`$) and then move forward ($`v`$)

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

#### Unicycle
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

$`u_1`$ = rate of change of steering angle\
$`u_2`$ = angular velocity of the wheel

Multiplying out each row from the matrix we can get the individual components:

**Heading/Yaw rate ($`\dot{\phi}`$)**

```math
\omega = \dot{\phi} = u_2
```

**Inertial x velocity ($`\dot{x}`$)**

```math
\dot{x} = v\cos(\phi)
```

**Inertial y velocity ($`\dot{y}`$)**

```math
\dot{y} = v\sin(\phi)
```

**Where did the linear velocity ($`v`$?) came from?**

From the matrix we simplified the linear velocity ($`v`$):

```math
v = ru_1
```

#### Differential drive
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

$`u_L`$ = angular velocity of left wheel\
$`u_R`$ = angular velocity of right wheel

Multiplying out each row from the matrix we can get the individual components:

**Angular velocity ($`\omega`$)**

```math
\omega = \dot{\phi} = \frac{r}{2d}(u_R-u_L)
```

**Inertial x velocity ($`\dot{x}`$)**

```math
\dot{x} = v\cos(\phi)
```

**Inertial y velocity ($`\dot{y}`$)**

```math
\dot{y} = v\sin(\phi)
```

**Where did the linear velocity ($`v`$?) came from?**

From the matrix we simplified the linear velocity ($`v`$):

```math
v = \frac{r}{2}(u_L+u_R)
```

#### Car-like
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

$`v`$ = linear forward speed\
$`\omega`$ = angular speed of the steering angle


## Motion control

Refers to the process of determining the appropiate control inputs to achieve a desired motion behavior while ensuring the robot remains **stable**.

Applicable **control types** depend on the robot type (ex. ground or underwater), actuation (ex. # control inputs), dynamics and constraints (ex. non/linear or non/holonomic), and taks (ex. mobile vs haptic).

The most fundamental **control categories** include <ins>motion (pos, vel, acc)</ins>, force, hybric motion-force, impedance control.

Quick comparison between categories and types:

| Control **categories** | Control **types** |
| --- | --- |
| What physical quantity are we regulating? | How do we mathematically formulate the commands given the robot's constraints? |
| *Fundamental domains*: motion, force, impedance | *Algorithmic implementations*: Trajectory tracking, path tracking, smooth vs discontinuous, etc. |
| Driven by nature of the robot's interaction with the environment | Driven by robot's kinematic morphology, actuation limits, and degree of non-holonomic constraints |


### Open Loop :curly_loop:

- Referred to as **feedforward** term
- Encodes the desired robot motion behavior (ex. forward, left, right, up, down)

### Closed Loop :loop:

- Referred to as **feedback** term
- Corrects the feedforward control input deviations

### State Space Representation :package:

- *State* is a vector $`x = \begin{bmatrix}
    x_1 & x_2 & \cdots & x_n
\end{bmatrix}^T`$
- State includes configuration: position ($`q`$), velocity ($`\dot{q}`$)

```math
q = \begin{bmatrix}
    q_1 & q_2 & \cdots & q_n
\end{bmatrix}^T
```

```math
x = \begin{bmatrix}
    q\\
    \dot{q}
\end{bmatrix}
```

```math
\underbrace{\dot{x}}_\text{rate of change of state}=f(\underbrace{x}_\text{current state}, \underbrace{u}_\text{input applied})
```

#### Example: spring-mass system

**Given:** $`m\ddot{q}(t)+kq(t)=u(t)`$

**Step 1: identify**\
2nd order differential equation

**Step 2: organize equation**
```math
\ddot{q}(t)=\frac{u(t)-kq(t)}{m}
```

**Step 3: set state vector**
```math
x = \begin{bmatrix}
    x_1 &x_2
\end{bmatrix}^T
=
\begin{bmatrix}
    q & \dot{q}
\end{bmatrix}^T
```

**Step 4: find coupled equations**
| $`x_1=q`$ | $`\dot{x_1}=\dot{q}=x_2`$ |
| --- | --- |
| $`x_2=\dot{q}`$ | $`\dot{x_2}=\ddot{q}=\frac{u-k\overbrace{q}^{x_1}}{m}=\frac{u-kx_1}{m}`$ |

**Step 5: write as matrix**
```math
\begin{bmatrix}
    \dot{x_1}\\
    \dot{x_2}
\end{bmatrix} = \begin{bmatrix}
    x_2\\
    \frac{u-kx_1}{m}
\end{bmatrix}
```

**Step 6: rewrite to satisfy linear system**\
To satisfy the linear system, we need to find a way to rewrite the matrox in the following form:
```math
\dot{x}=\underbrace{Ax}_\text{matrix A that multiplies state x}+\underbrace{Bu}_\text{vector B that multiplies control input u}
```

```math
\begin{bmatrix}
    \dot{x_1}\\
    \dot{x_2}
\end{bmatrix} = \begin{bmatrix}
    0 & x_2\\
    -\frac{k}{m} & 0
\end{bmatrix}
\begin{bmatrix}
    x_1\\
    x_2
\end{bmatrix}
+ \begin{bmatrix}
    0\\
    \frac{1}{m}
\end{bmatrix} u
```

Not always is possible to rewrite, if we cannot, then it's considered a **non-linear system.**

Some tips to identify a non-linear system:
- contains a trig function (sin, cos, tan, etc.)
- x contains powers (ex. $`x_1^2`$ or $`x_2^3`$ )

#### Example: damped pendulum

**Given:** $`\ddot{q}+\frac{c}{ml^2}\dot{q}+\frac{g}{l}\sin{q}=0`$

**Step 1: identify**\
2nd order differential equation

**Step 2: organize equation**
```math
\ddot{q}=-\frac{c}{ml^2}\dot{q}-\frac{g}{l}\sin{q}
```

**Step 3 & 4: set state vector and find coupled equations**
```math
x = \begin{bmatrix}
    x_1 & x_2
\end{bmatrix}^T
=
\begin{bmatrix}
    q & \dot{q}
\end{bmatrix}^T
```

| $`x_1=q`$ | $`\dot{x_1}=\dot{q}=x_2`$ |
| --- | --- |
| $`x_2=\dot{q}`$ | $`\dot{x_2}=-\frac{c}{ml^2}x_2-\frac{g}{l}\sin{x_1}`$ |

**Step 5: write as matrix**
```math
\begin{bmatrix}
    \dot{x_1}\\
    \dot{x_2}
\end{bmatrix} = \begin{bmatrix}
    x_2\\
    -\frac{c}{ml^2}x_2-\frac{g}{l}\sin{x_1}
\end{bmatrix}
```

**non-linear**

#### Example: 4-dimensional state vectors

**Given:**
```math
(M+m)\ddot{x}+mL\ddot{\theta}\cos{\theta}-mL\dot{\theta}^2\sin{\theta}=u(t)
```

```math
mL\ddot{x}\cos{\theta}+mL^2\ddot{\theta}-mgL\sin{\theta}=0
```

**Step 1: identify**\
Two 2nd order differential equations

**Step 2: organize equation**\
Need to solve for 1 equation, replace, and repeat until getting 2 equations: one for $`\ddot{theta}`$ and one for $`\ddot{x}`$

```math
\ddot{x}=\frac{u(t)-mg\sin{\theta}\cos{\theta}+mL\dot{\theta}^2\sin{\theta}}{M+m\sin^2{\theta}}
```

```math
\ddot{\theta}=\frac{Mg\sin{\theta}+mg\sin{\theta}-u(t)\cos{\theta}+mL\dot{\theta}^2\sin{\theta}\cos{\theta}}{L(M+m\sin^2{\theta})}
```

**Step 3 & 4: set state vector and find coupled equations**\
```math
x = \begin{bmatrix}
    x_1 & x_2 & x_3 & x_4 
\end{bmatrix}^T
=
\begin{bmatrix}
    x & \dot{x} & \theta & \dot{\theta}
\end{bmatrix}^T
```

| $`x_1=x`$ | $`\dot{x_1}=\dot{x}=x_2`$ |
| --- | --- |
| $`x_2=\dot{x}`$ | $`\dot{x_2}=\frac{u-mg\sin{x_3}\cos{x_3}+mLx_4^2\sin{x_3}}{M+m\sin^2{x_3}}`$ |

| $`x_3=\theta`$ | $`\dot{x_3}=\dot{x=\theta}=x_4`$ |
| --- | --- |
| $`x_4=\dot{\theta}`$ | $`\dot{x_4}=\frac{Mg\sin{x_3}+mg\sin{x_3}-u\cos{x_3}+mLx_4^2\sin{x_3}\cos{x_3}}{L(M+m\sin^2{x_3})}`$ |

**Step 5: write as matrix**\
```math
\begin{bmatrix}
    \dot{x_1}\\
    \dot{x_2}
    \dot{x_3}
    \dot{x_4}
\end{bmatrix} = \begin{bmatrix}
    x_2\\
    \cdots\\
    x_4\\
    \cdots
\end{bmatrix}
```

**non-linear**


### Heuristics :thinking:

**Heuristics** refer to the process of estimating a distance from an initial point to a final point using either of two methods:

#### Euclidean distance ($`L_2`$ norm)

Estimates the distance as a straight line from the current point $`x y`$ to the final/end point $`x_G y_G`$.

```math
h=\sqrt{(x-x_G)^2+(y-y_G)^2}
```

#### Manhattan distance ($`L_1`$ norm)

Estimates the distance using a square grid (vertical or horizontal only, no diagonal lines) from the current point $`x y`$ to the final/end point $`x_G y_G`$.

```math
h=|(x-x_G)^2|+|(y-y_G)^2|
```


### A* search algorithm :mag:

It's important to have an **adjacency graph** or **occupancy grid** to perform the A* algorithm. Build a table with all the nodes and their corresponding heuristic ($`h(n)`$) values. Build the table and start checking the nodes, adding them to the open list, checking the neighbor nodes/cells, until getting to the end node.

$`f(n)=g(n)+h(n)`$ where $`g(n)`$ is the past cost, $`h(n)`$ is the heuristic value, and $`f(n)`$ is the total weight of that node

| | Start node | Node 1 | Node 2 | $`\cdots`$ | Goal node |
| --- | --- | --- | --- | --- | --- |
| $`g(n)`$ | 0 | ~ | ~ | $`\cdots`$ | x |
| $`h(n)`$ | x | ~ | ~ | $`\cdots`$ | 0 |
| $`f(n)`$ | x | ~ | ~ | $`\cdots`$ | x |
| parent | - | ~ | ~ | $`\cdots`$ | ~ |

**open list**\
Node 2(e.g. weight: 2), Node 1(e.g. weight: 3) $`\cdots`$

**closed list**
Start node $`\cdots`$

When reaching the goal, the A* algorithm will return the **optimal path**.

#### Grids

The A* algorithm works the same for an occupancy grid. However, there are 2 types of performing the search:

##### 4-connected graphs

Each node is connected to 4 neighbors: Top, bottom, left, and right.

```math
\begin{matrix}
   & \circ &  \\
  \circ & \bullet & \circ \\
   & \circ &
 \end{matrix}
```

##### 8-connected graphs

Each node is connected to 8 neighbors: Top, bottom, left, and right, diagonal.

```math
\begin{matrix}
  \circ & \circ & \circ \\
  \circ & \bullet & \circ \\
  \circ & \circ & \circ
 \end{matrix}
```



<!-- ### Degrees of Freedom (DoF)
Minimum number of constraints needed to complete a configuration

### Kinematic Constraints
Holonomic vs no holonomic
differential drive kinematics
-->

## Misc Q&A :question:

### Why are frames important?

Mainly to get the correct coordinates. Sensors are located in different positions with respect to the **base frame**. To get accurate mathematical conversions, mapping, and movement, we need to take the points gathered by the sensors and translate and rotate them so they can be processed accordingly.

### How many frames can a robot have?

As many as needed. They are represented and organized in a hierarchical tree (TF tree). Every rigid link and sensor has its own frame (ex. base_link, shoulder, elbow, wheel_left, wheel_right, lidar, camera)