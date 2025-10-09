<div align="center">

# ATRI-2024

***[汉语](README.md)***

**Ace Team of Robotics Intelligence 2024 FIRA SimuroSot 11vs11 Client**

[![License](https://img.shields.io/badge/License-NCND--Software--1.0-blue.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)
[![Framework](https://img.shields.io/badge/Framework-MFC-orange.svg)](https://docs.microsoft.com/en-us/cpp/mfc/mfc-desktop-applications)

</div>

## 📖 Project Overview

ATRI-2024 is a FIRA SimuroSot 11vs11 simulated robot soccer client developed by **Ace Team of Robotics Intelligence (ATRI)** for the **2024 China Robot Competition & RoboCup China Open**.

Built on the MFC (Microsoft Foundation Classes) framework, this project implements a complete robot soccer strategy system, including player control, tactical decision-making, communication protocols, and other core functionalities.

## 👥 Team Members

**Team Leader:**

- [@xixu-me](https://github.com/xixu-me)

**Team Members:**

- [@XIAOLingQ](https://github.com/XIAOLingQ)
- [@Wx-debug](https://github.com/Wx-debug)
- [@moxun333](https://github.com/moxun333)
- [@song-yaya](https://github.com/song-yaya)
- [@huaxiaoshi](https://github.com/huaxiaoshi)
- [@biqianq](https://github.com/biqianq)
- [@isWorldEdit](https://github.com/isWorldEdit)

## ✨ Key Features

### Core Modules

- **Strategy System** (`StrategySystem`): Implements team tactical decision-making and execution
  - Goalie Strategy
  - Possession Strategy
  - Freeball Strategy
  - Penalty Strategy
  - Shot Control
  - Formation Management

- **Communication System** (`AgentSocket`): Socket communication with simulation server
  - Connection Management
  - Data Reception & Parsing
  - Command Transmission

- **Base Agent** (`BaseAgent`): Player basic behavior control
  - Motion Control
  - Position Tracking
  - Angle Calculation

- **Graphical Interface** (`MicroClientView`): Visualization and debugging
  - Real-time Field Display
  - Robot Position Visualization
  - Strategy Debugging Interface

## 🏗️ Project Structure

```
ATRI-2024/
├── src/                          # Source code files (.cpp)
│   ├── Agentsock.cpp            # Socket communication implementation
│   ├── BaseAgent.cpp            # Base agent implementation
│   ├── DSetupDlg.cpp            # Setup dialog implementation
│   ├── MainFrm.cpp              # Main frame window implementation
│   ├── MicroClient.cpp          # Application entry point
│   ├── MicroClientDoc.cpp       # Document class implementation
│   ├── MicroClientView.cpp      # View class implementation
│   ├── StdAfx.cpp               # Precompiled header source
│   ├── StrategySystem.cpp       # Core strategy system implementation
│   └── TParseString.cpp         # String parsing utilities
│
├── include/                      # Header files (.h)
│   ├── Agentsock.h              # Socket communication interface
│   ├── BaseAgent.h              # Base agent interface
│   ├── DSetupDlg.h              # Setup dialog interface
│   ├── General.h                # General definitions and data structures
│   ├── MainFrm.h                # Main frame window interface
│   ├── MicroClient.h            # Application main interface
│   ├── MicroClientDoc.h         # Document class interface
│   ├── MicroClientView.h        # View class interface
│   ├── RESOURCE.H               # Resource ID definitions
│   ├── StdAfx.h                 # Precompiled header
│   ├── StrategySystem.h         # Strategy system interface
│   └── TParseString.h           # String parsing utilities interface
│
├── RES/                          # Resource files
│   ├── MicroClient.ico          # Application icon
│   ├── MicroClient.rc2          # Additional resources
│   ├── MicroClientDoc.ico       # Document icon
│   └── Toolbar.bmp              # Toolbar bitmap
│
├── docs/                         # Documentation
│   ├── Contest-Rules-2024.pdf   # 2024 Contest rules
│   ├── Field Coordinates.jpg    # Field coordinate system reference
│   └── STRUCTURE.md             # Project structure documentation
│
├── MicroClient.sln              # Visual Studio solution file
├── MicroClient.vcxproj          # Visual Studio project file (2010+)
├── MicroClient.vcxproj.filters  # Project filters
├── MicroClient.rc               # Resource script
├── README.md                    # Project documentation (Chinese)
├── README.en.md                 # Project documentation (English)
└── LICENSE                      # License file
```

## 🚀 Quick Start

### Requirements

- **Operating System**: Windows 7 or higher
- **Development Tool**: Visual Studio 2010 or higher
- **Framework**: MFC (Microsoft Foundation Classes)
- **Dependencies**: Windows Sockets API

### Build Instructions

1. **Clone the repository**

   ```bash
   git clone https://github.com/xixu-me/ATRI-2024.git
   cd ATRI-2024
   ```

2. **Open the project**
   - Open `MicroClient.sln` with Visual Studio

3. **Configure the project**
   - Ensure the project is configured for Release or Debug mode
   - Check include directories and library directory settings

4. **Build**
   - Press `F7` or select **Build → Build Solution**
   - After compilation, the executable will be in the `Debug/` or `Release/` directory

### Running the Program

1. Start the FIRA SimuroSot simulation server
2. Run the compiled `MicroClient.exe`
3. Configure in the setup dialog:
   - Server address (default: localhost)
   - Port number (default: 5001)
   - Team name
4. Click connect to start the match

## 🎯 Strategy System

### System Architecture

The Strategy System (`CStrategySystem`) is the core module of this project, responsible for the entire team's tactical decision-making, formation adjustment, and player control. The system adopts a **state machine pattern**, dynamically switching strategies based on match scenarios, implementing a complete 11vs11 robot soccer intelligent decision-making system.

#### Main Control Flow

```cpp
void CStrategySystem::Action() {
    T++;  // Cycle counter
    Goalie();  // Goalie strategy (runs continuously)
    
    switch (Status()) {
        case 1:  // Penalty state
            flag = true;
            Penalty();
            break;
        default:  // Normal match state
            flag = true;
            Possession();  // Possession strategy
            break;
    }
}
```

### Core Strategy Modules

#### 1. Goalie Strategy

The goalie strategy is the last line of defense, employing a **multi-level predictive defense algorithm** that combines ball trajectory analysis, opponent shooting threat assessment, and intelligent positioning adjustment for efficient goal protection.

---

##### 1.1 Core Architecture

The goalie strategy executes every cycle (runs independently from other strategies in `Action()`), including the following core modules:

```cpp
void CStrategySystem::Goalie() {
    if (start)
        ball.oldPosition = ball.position;
        
    if (ball.position.x <= hgoalie.position.x) {
        // Ball is behind goalie → Execute defense strategy
        Calculate target position (xix, xiy)
        Direction(HGOALIE, CPoint(xix, xiy));
    }
    else {
        // Ball is in front of goalie → Stop moving (teammate controls ball)
        Stop(HGOALIE);
    }
    
    ball.oldPosition = ball.position;  // Update historical position
}
```

**Key Decision**: Defense is only activated when the ball is behind the goalie (`ball.position.x <= hgoalie.position.x`), avoiding blind rushes.

---

##### 1.2 Threat Assessment System

###### Shooting Threat Player Identification (`shooter_pos()`)

The system identifies the most threatening shooting player from the opponent in real-time:

```cpp
CPoint CStrategySystem::shooter_pos() {
    // 1. Get positions of opponent's 11 players
    CPoint cur_pos[11] = { opponent.position1, ..., opponent.position11 };
    
    // 2. Filter: Exclude players behind the ball (cannot shoot)
    for (int i = 0; i < 11; i++) {
        if (cur_pos[i].x >= ball.position.x)
            cur_pos[i] = CPoint(-965, -723);  // Mark as invalid position
    }
    
    // 3. Calculate nearest opponent to ball (most threatening)
    int threat_id = 0;
    double min_distance = Distance(cur_pos[0], ball.position);
    for (int i = 1; i < 11; i++) {
        if (Distance(cur_pos[i], ball.position) < min_distance) {
            min_distance = Distance(cur_pos[i], ball.position);
            threat_id = i;
        }
    }
    
    return cur_pos[threat_id];  // Return threat player position
}
```

**Threat Determination Logic**:

- Only considers opponent players in front of the ball (capable of shooting)
- Closer to ball = Greater threat
- Dynamic updates, re-evaluates every cycle

---

##### 1.3 Position Prediction Algorithm

The goalie uses **dual-mode prediction**, selecting the optimal prediction method based on ball movement state:

###### Mode 1: Trajectory Prediction (Ball in Motion)

When ball speed is sufficient and movement direction is clear, uses **linear trajectory extrapolation**:

```cpp
// Calculate predicted Y coordinate at goal line (X=965)
double dy = ball.position.y - ball.oldPosition.y;
double dx = ball.position.x - ball.oldPosition.x;

// Linear equation: y = kx + b
// k = dy/dx, b = y0 - k*x0
int xii = (dy/dx) * 965 + (ball.oldPosition.y - (dy/dx) * ball.oldPosition.x);
```

**Trigger Conditions**:

- `Distance(ball.position, ball.oldPosition) >= 1` (ball is moving)
- `ball.position.x > ball.oldPosition.x` (ball heading toward our goal)
- `313 <= xii <= 505` (prediction point within goal range)

###### Mode 2: Threat Player Prediction (Ball Static or Prediction Failed)

When trajectory prediction is unavailable, predicts shooting direction based on **line between threat player and ball**:

```cpp
CPoint shooter = shooter_pos();  // Get threat player position

// Calculate intersection of shooting line and goal line
double dy = ball.position.y - shooter.y;
double dx = ball.position.x - shooter.x;
int xii = (dy/dx) * 965 + (shooter.y - (dy/dx) * shooter.x);

if (xii < 313 || xii > 505) {
    // Prediction point outside goal → Use weighted center method
    xiy = (Distance(ball, CPoint(863,313)) * 192 / 
           (Distance(ball, CPoint(863,313)) + Distance(ball, CPoint(863,505)))) + 313.5;
}
```

**Weighted Center Method**: When shooting line doesn't pass through the goal, the goalie stands at the weighted distance center between the two goalposts, covering a larger angle.

---

##### 1.4 Positioning Strategy

###### X-axis Positioning (Depth Control)

```cpp
int xix = ball.position.x > 950 ? 965 : 950;  // Base position
int xid = 2;  // Forward compensation

if (Predicted Y < 343 || Predicted Y > 475) {
    xix = 965;  // Close to goal line (cover goal corners)
}
else {
    xix = 950;  // Move forward to 950 (expand defense range)
}
```

**Depth Layers**:

- **965** (goal line): When ball heads toward goal corners, defend close to goal line
- **950** (forward position): When ball heads toward goal center, move forward to expand interception range
- **Dynamic adjustment**: Switches in real-time based on prediction point

###### Y-axis Positioning (Horizontal Coverage)

```cpp
// Trajectory prediction mode
xiy = (dy/dx) * (xix - xid) + (ball.oldPosition.y - (dy/dx) * ball.oldPosition.x);

// Threat player prediction mode
xiy = (dy/dx) * (xix - xid) + (shooter.y - (dy/dx) * shooter.x);

// Boundary limits
xiy = max(313, min(505, xiy));  // Limit within goal range
```

###### Small-Range Oscillation (Confuse Opponent)

When the ball is at a distance and doesn't form a direct threat, the goalie oscillates left and right in a small range at the goal line center:

```cpp
if (ball.position.x <= 900 || ball.position.y < 313 || ball.position.y > 505) {
    if ((T / 4) % 2)  // Switch every 4 cycles
        xiy += 30;     // Oscillate downward
    else
        xiy -= 30;     // Oscillate upward
}
```

**Oscillation Effects**:

- Prevents goalie from being static (avoid pinpoint targeting)
- Increases opponent shooting difficulty (dynamic target harder to aim at)
- Maintains reaction activity (faster response to sudden threats)

---

##### 1.5 Motion Control

The goalie uses the `Direction()` function for position movement, which implements a **PD controller**:

```cpp
void CStrategySystem::Direction(int which, CPoint point) {
    // 1. Calculate target point (extension line strategy, enhance responsiveness)
    point.x = 2 * point.x - robot->position.x;
    point.y = 2 * point.y - robot->position.y;
    
    // 2. Boundary limits
    point = Limit within field range;
    
    // 3. Calculate position error and angle error
    dx = point.x - robot->position.x;
    dy = point.y - robot->position.y;
    distance_e = sqrt(dx² + dy²);
    desired_angle = atan2(dy, dx) * 180/π;
    theta_e = desired_angle - robot->angle;
    
    // 4. PD controller calculates wheel speeds
    vL = 5.0 * (0.1 * distance_e + 0.444 * theta_e);
    vR = 5.0 * (0.1 * distance_e - 0.444 * theta_e);
    
    // 5. Send velocity command
    Velocity(which, vL, vR);
}
```

**Control Parameters**:

- **Proportional coefficient (distance)**: 0.1 → Farther distance, faster speed
- **Proportional coefficient (angle)**: 0.444 → Larger angle deviation, sharper turn
- **Amplification factor**: 5.0 → Overall speed amplification

---

##### 1.6 Special Case Handling

###### Ball in Front of Goalie

```cpp
if (ball.position.x > hgoalie.position.x) {
    Stop(HGOALIE);  // Stop moving, save energy, avoid interfering with teammates
}
```

###### Prediction Failure Protection

When all prediction modes fail (extreme cases), the goalie returns to the goal center on standby:

```cpp
if (All prediction modes failed) {
    xix = 965;
    xiy = 409;  // Goal center Y coordinate
}
```

---

##### 1.7 Performance Optimization

**Computation Optimization**:

- Use integer arithmetic instead of floating-point (`int(calculation + 0.5)` rounding)
- Cache `ball.oldPosition`, avoid repeated access
- Calculate `shooter_pos()` only when needed (conditional trigger)

**Response Optimization**:

- Executes every cycle (parallel with other strategies)
- No decision delay (real-time calculation → immediate execution)
- Dual-mode prediction (ensures always valid prediction)

---

##### 1.8 Technical Highlights

1. **Multi-mode Fusion**: Trajectory prediction + Threat player prediction, complementary
2. **Layered Positioning**: X-axis depth + Y-axis horizontal, two-dimensional optimization
3. **Dynamic Oscillation**: Small-range random movement, increases defensive uncertainty
4. **Intelligent Filtering**: Only tracks threat players behind the ball, avoids misjudgment
5. **PD Control**: Smooth motion, avoids jitter and overshoot
6. **Boundary Protection**: All calculation results undergo boundary checks, ensuring legality

---

#### 2. Possession Strategy

The possession strategy is the most complex module, employing a **dynamic formation system** that automatically selects the optimal formation based on field position and assigns positions to each player through an **intelligent allocation algorithm**.

##### 2.1 Formation System

The field is divided into **3×3 = 9 zones**, each corresponding to a specific formation:

```text
Field Zones (from our goal to opponent goal):
┌─────────────┬─────────────┬─────────────┐
│ Formation 1 │ Formation 4 │ Formation 7 │  Y < 217 (upper)
│ (L-U Def)   │ (C-U Attack)│ (R-U Rush)  │
├─────────────┼─────────────┼─────────────┤
│ Formation 3 │ Formation 6 │ Formation 9 │  217-607 (middle)
│ (L-M Def)   │ (Midfield)  │ (R-M Rush)  │
├─────────────┼─────────────┼─────────────┤
│ Formation 2 │ Formation 5 │ Formation 8 │  Y > 607 (lower)
│ (L-D Def)   │ (C-D Attack)│ (R-D Rush)  │
└─────────────┴─────────────┴─────────────┘
   X < 290      290-740       X > 740
```

**Formation ID Calculation:**

```cpp
int CStrategySystem::fm_id() {
    if (ball.position.x < 290) {
        if (ball.position.y < 217) return 1;      // Left-upper
        else if (ball.position.y <= 607) return 3; // Left-middle
        else return 2;                             // Left-lower
    }
    else if (ball.position.x < 740) {
        if (ball.position.y < 217) return 4;      // Center-upper
        else if (ball.position.y <= 607) return 6; // Center-middle
        else return 5;                             // Center-lower
    }
    else {
        if (ball.position.y < 217) return 7;      // Right-upper
        else if (ball.position.y <= 607) return 9; // Right-middle
        else return 8;                             // Right-lower
    }
}
```

##### 2.2 Central Player Selection

Each formation has a **central player** (`cp_id()`), serving as the offensive core, responsible for directly chasing the ball. Other players form around the central player.

**Selection Strategy:**

- **Offensive formations (1, 2, 7, 8)**: Select player closest to ball with suitable Y coordinate
- **Midfield formations (4, 5, 6)**: Select player closest to ball and in front of ball (X > ball.x)
- **Special zones**: Near penalty area, prioritize player with closest Y coordinate

```cpp
int CStrategySystem::cp_id() {
    CPoint cur_pos[10] = { home1.position, ..., home10.position };
    
    if (fm_id() == 1) {  // Left-upper formation
        // Filter: Only consider players with Y >= ball.position.y
        Screen qualified players
        Return closest player ID to ball
    }
    // Similar logic for other formations...
}
```

##### 2.3 Player Position Assignment

Uses **layered sorting algorithm** (`fp_sort()`) to assign positions to formation players:

1. **First layer**: Sort by distance to central player (find nearest players)
2. **Second layer**: Sort by relative angle (from top to bottom or left to right)
3. **Assignment execution**: Nearest players assigned to nearest formation positions

##### Example: Formation 6 (Midfield Formation)

```cpp
if (fm_id() == 6) {
    Direction(cp_id(), ball.position);  // Central player directly chases ball
    
    // Define formation positions (polar coordinate style)
    pos[1] = CPoint(ball.x + cos(-90°)*20, ball.y + sin(-90°)*20);
    pos[2] = CPoint(ball.x + cos(90°)*20,  ball.y + sin(90°)*20);
    pos[3] = CPoint(pos[0].x + cos(-45°)*40, pos[0].y + sin(-45°)*40);
    pos[4] = CPoint(pos[0].x + cos(0°)*40,   pos[0].y + sin(0°)*40);
    pos[5] = CPoint(pos[0].x + cos(45°)*40,  pos[0].y + sin(45°)*40);
    // ... More positions
    
    // Layered assignment
    fp_sort(rp);           // Sort all players by distance
    fp_sort(rp, 0, 2);     // Sort first 2 by angle
    Direction(rp[1].id, pos[1]);
    Direction(rp[2].id, pos[2]);
    // ... Assign other positions
}
```

**Typical Formation Layouts:**

- **Formation 1/2 (Left Defense)**: Layered defense, formation players distributed to right and front of central player
- **Formation 4/5 (Midfield Transition)**: Fan-shaped spread, maintain passing lanes
- **Formation 6 (Midfield Circle)**: 360° circular encirclement, adapts to any attack direction
- **Formation 7/8 (Right Rush)**: Concentrated forward press, forms shooting threat
- **Formation 9 (Penalty Area Attack)**: Adjusts upper/lower focus based on ball's Y coordinate

---

#### 3. Penalty Strategy

The penalty strategy employs a **curved driving algorithm**, achieving arc shooting through differential left-right wheel speed control.

**Strategy Features:**

- **Randomness**: Randomly selects upper or lower route shooting (50% probability)
- **Two-stage Control**:
  1. **Approach Stage**: Straight rush toward ball (distance > 21)
  2. **Shooting Stage**: Curve adjustment, aim at goal corner (distance ≤ 21)

**Curved Shooting Algorithm:**

```cpp
// Calculate trajectory radius
double r = Distance(robot, ball) / (2 * sin(θ))

// Differential speed control
int lw = r / (r + 6) * 127  // Reduce inner wheel speed
Velocity(1, lw, 127)         // Left slow right fast → Right turn
```

**Target Points:**

- Upper route: `(28, 313)` - Upper goal corner
- Lower route: `(28, 505)` - Lower goal corner

---

#### 4. Shot Control

The shooting system includes multiple overloaded functions, supporting shooting needs in different scenarios.

##### 4.1 Basic Shot (`shot(int which)`)

Automatically selects optimal shooting angle, avoids defensive players.

##### 4.2 Directional Shot (`shot(int which, CPoint t)`)

Shoots toward specified target point, used for passing or tactical coordination.

##### 4.3 Direct Shot Control (`shot1(int which, double o, CPoint t)`)

Lowest-level shooting implementation, precisely controls shooting parameters.

**Shooting Decision Flow:**

1. Check shooting conditions (`canshot()`)
2. Calculate shooting angle and power
3. Adjust robot orientation
4. Execute acceleration rush

---

### Auxiliary Algorithms

#### Motion Control

- **Direction(int which, CPoint point)**: Move toward a point
- **Position(int which, CPoint point)**: Precisely move to a point (PD control)
- **PositionSE(int which, CPoint point)**: Position without entering penalty area
- **Rush(int which, CPoint point)**: Rush toward a point at full speed
- **Velocity(int which, int vL, int vR)**: Low-level velocity control

#### Geometric Calculations

- **Distance(CPoint p1, CPoint p2)**: Distance between two points
- **Angle(CPoint p1, CPoint p2)**: Angle between two points
- **atwo(...)**: Calculate angle between two lines

#### Scenario Detection

- **Status()**: Determine match state (penalty, freeball, normal)
- **search1() / search2()**: Search for robots in specific areas
- **shooter_pos()**: Identify opponent shooting threat player

---

### Technical Highlights

1. **Adaptive Formation System**: Automatically switches 9 formations based on 9 field zones
2. **Layered Intelligent Assignment**: Distance-angle two-level sorting, ensures optimal player positions
3. **Predictive Defense**: Goalie predicts ball trajectory in advance, not passive reaction
4. **Penalty Area Avoidance Logic**: `PositionSE` automatically avoids own penalty area, prevents violations
5. **Curved Driving Algorithm**: Geometry-based differential speed control, achieves precise arc motion
6. **State Machine Architecture**: Clear strategy switching logic, easy to extend and debug

---

### Performance Characteristics

- **Real-time Response**: Completes one decision per cycle (approximately 100ms)
- **Concurrent Control**: Simultaneously controls 11 players (10 field players + 1 goalie)
- **Robustness**: Supports player loss, communication delay, and other anomalies
- **Extensibility**: Modular design, easily add new formations and strategies

## 📊 Data Structures

### Robot Data (`Robot1`, `Robot2`, `Robot3`)

```cpp
struct Robot1 {
    int angle;              // Robot angle
    CPoint position;        // Current position
    CPoint oldPosition;     // Historical position
    BOOL bAlive;           // Alive status
};
```

### Control Command (`CCommand`)

```cpp
union CCommand {
    BYTE Stream[3];
    struct tagData {
        char Lv;           // Left wheel velocity
        char Rv;           // Right wheel velocity
        char Command;      // Control command
    } Data;
};
```

## 🔧 Configuration

### Field Parameters

- **Field Dimensions**: See `docs/Field Coordinates.jpg`
- **Coordinate System**: Cartesian coordinate system, origin at field center
- **Angle Range**: 0-360° (clockwise)

### Communication Protocol

- **Protocol Type**: TCP/IP Socket
- **Data Format**: Text protocol
- **Default Port**: 5001

## 📄 License

This project is licensed under the **Noncommercial No-Derivatives Software License 1.0**.

- ✅ Permitted for non-commercial use and reproduction
- ✅ Permitted for academic research and teaching
- ❌ Prohibited for commercial use
- ❌ Prohibited from distributing modified versions

For details, see the [LICENSE](LICENSE) file.

## 🤝 Contributing

This project currently does not accept external contributions.

## 🙏 Acknowledgments

Thanks to all team members for their hard work and to the China Robot Competition Organizing Committee for providing the competition platform.

---

<div align="center">

**Go ATRI! 🏆**

*Made with ❤️ by ATRI Team*

</div>
