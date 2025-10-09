<div align="center">

# ATRI-2024

***[English](README.en.md)***

**机器人智能王牌战队 2024 FIRA SimuroSot 11vs11 客户端**

[![License](https://img.shields.io/badge/License-NCND--Software--1.0-blue.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)
[![Framework](https://img.shields.io/badge/Framework-MFC-orange.svg)](https://docs.microsoft.com/en-us/cpp/mfc/mfc-desktop-applications)

</div>

## 📖 项目简介

ATRI-2024 是由**机器人智能王牌战队**（**A**ce **T**eam of **R**obotics **I**ntelligence，ATRI）开发的 FIRA SimuroSot 11vs11 仿真机器人足球客户端，用于备战 **2024 中国机器人大赛暨 RoboCup 机器人世界杯中国赛**。

本项目基于 MFC (Microsoft Foundation Classes) 框架开发，实现了完整的机器人足球策略系统，包括球员控制、战术决策、通信协议等核心功能。

## 👥 团队成员

**队长：**

- [@xixu-me](https://github.com/xixu-me)

**队员：**

- [@XIAOLingQ](https://github.com/XIAOLingQ)
- [@Wx-debug](https://github.com/Wx-debug)
- [@moxun333](https://github.com/moxun333)
- [@song-yaya](https://github.com/song-yaya)
- [@huaxiaoshi](https://github.com/huaxiaoshi)
- [@biqianq](https://github.com/biqianq)
- [@isWorldEdit](https://github.com/isWorldEdit)

## ✨ 主要功能

### 核心模块

- **策略系统** (`StrategySystem`)：实现球队的战术决策与执行
  - 守门员策略 (Goalie)
  - 控球策略 (Possession)
  - 争球策略 (Freeball)
  - 罚球策略 (Penalty)
  - 射门控制 (Shot)
  - 阵型管理 (Formation)

- **通信系统** (`AgentSocket`)：与仿真服务器的 Socket 通信
  - 连接管理
  - 数据接收与解析
  - 命令发送

- **基础代理** (`BaseAgent`)：球员基础行为控制
  - 运动控制
  - 位置跟踪
  - 角度计算

- **图形界面** (`MicroClientView`)：可视化显示与调试
  - 实时场地显示
  - 机器人位置可视化
  - 策略调试界面

## 🏗️ 项目结构

```
ATRI-2024/
├── src/                          # 源代码文件 (.cpp)
│   ├── Agentsock.cpp            # Socket 通信实现
│   ├── BaseAgent.cpp            # 基础代理实现
│   ├── DSetupDlg.cpp            # 设置对话框实现
│   ├── MainFrm.cpp              # 主框架窗口实现
│   ├── MicroClient.cpp          # 应用程序主入口
│   ├── MicroClientDoc.cpp       # 文档类实现
│   ├── MicroClientView.cpp      # 视图类实现
│   ├── StdAfx.cpp               # 预编译头源文件
│   ├── StrategySystem.cpp       # 核心策略系统实现
│   └── TParseString.cpp         # 字符串解析工具
│
├── include/                      # 头文件 (.h)
│   ├── Agentsock.h              # Socket 通信接口
│   ├── BaseAgent.h              # 基础代理接口
│   ├── DSetupDlg.h              # 设置对话框接口
│   ├── General.h                # 通用定义与数据结构
│   ├── MainFrm.h                # 主框架窗口接口
│   ├── MicroClient.h            # 应用程序主接口
│   ├── MicroClientDoc.h         # 文档类接口
│   ├── MicroClientView.h        # 视图类接口
│   ├── RESOURCE.H               # 资源 ID 定义
│   ├── StdAfx.h                 # 预编译头
│   ├── StrategySystem.h         # 策略系统接口
│   └── TParseString.h           # 字符串解析工具接口
│
├── RES/                          # 资源文件
│   ├── MicroClient.ico          # 应用程序图标
│   ├── MicroClient.rc2          # 附加资源
│   ├── MicroClientDoc.ico       # 文档图标
│   └── Toolbar.bmp              # 工具栏位图
│
├── docs/                         # 文档
│   ├── Contest-Rules-2024.pdf   # 2024 赛事规则
│   ├── Field Coordinates.jpg    # 场地坐标系参考
│   └── STRUCTURE.md             # 项目结构说明
│
├── MicroClient.sln              # Visual Studio 解决方案文件
├── MicroClient.vcxproj          # Visual Studio 项目文件 (2010+)
├── MicroClient.vcxproj.filters  # 项目过滤器
├── MicroClient.rc               # 资源脚本
├── README.md                    # 项目说明文档
└── LICENSE                      # 许可证文件
```

## 🚀 快速开始

### 环境要求

- **操作系统**：Windows 7 或更高版本
- **开发工具**：Visual Studio 2010 或更高版本
- **框架**：MFC (Microsoft Foundation Classes)
- **依赖项**：Windows Sockets API

### 编译步骤

1. **克隆仓库**

   ```bash
   git clone https://github.com/xixu-me/ATRI-2024.git
   cd ATRI-2024
   ```

2. **打开项目**
   - 使用 Visual Studio 打开 `MicroClient.sln`

3. **配置项目**
   - 确保项目配置为 Release 或 Debug 模式
   - 检查包含目录和库目录设置

4. **编译**
   - 按 `F7` 或选择 **生成 → 生成解决方案**
   - 编译完成后，可执行文件位于 `Debug/` 或 `Release/` 目录

### 运行程序

1. 启动 FIRA SimuroSot 仿真服务器
2. 运行编译生成的 `MicroClient.exe`
3. 在设置对话框中配置：
   - 服务器地址（默认：localhost）
   - 端口号（默认：5001）
   - 队伍名称
4. 点击连接，开始比赛

## 🎯 策略系统

### 系统架构

策略系统（`CStrategySystem`）是本项目的核心模块，负责整个球队的战术决策、阵型调整和球员控制。系统采用**状态机模式**，根据比赛场景动态切换策略，实现了完整的 11vs11 足球机器人智能决策系统。

#### 主控制流程

```cpp
void CStrategySystem::Action() {
    T++;  // 周期计数器
    Goalie();  // 守门员策略（持续运行）
    
    switch (Status()) {
        case 1:  // 罚球状态
            flag = true;
            Penalty();
            break;
        default:  // 正常比赛状态
            flag = true;
            Possession();  // 控球策略
            break;
    }
}
```

### 核心策略模块

#### 1. 守门员策略（Goalie）

守门员策略是防守体系的最后一道防线，采用**多层次预测式防守算法**，结合球的运动轨迹分析、对方射门威胁评估和智能站位调整，实现高效的球门保护。

---

##### 1.1 核心架构

守门员策略在每个周期都会执行（在 `Action()` 中独立于其他策略运行），包含以下核心模块：

```cpp
void CStrategySystem::Goalie() {
    if (start)
        ball.oldPosition = ball.position;
        
    if (ball.position.x <= hgoalie.position.x) {
        // 球在守门员后方 → 执行防守策略
        计算目标位置 (xix, xiy)
        Direction(HGOALIE, CPoint(xix, xiy));
    }
    else {
        // 球在守门员前方 → 停止移动（队友控球）
        Stop(HGOALIE);
    }
    
    ball.oldPosition = ball.position;  // 更新历史位置
}
```

**关键判断**：仅当球在守门员身后（`ball.position.x <= hgoalie.position.x`）时才启动防守，避免守门员盲目出击。

---

##### 1.2 威胁评估系统

###### 射门威胁球员识别（`shooter_pos()`）

系统会实时识别对方最具威胁的射门球员：

```cpp
CPoint CStrategySystem::shooter_pos() {
    // 1. 获取对方 11 个球员的位置
    CPoint cur_pos[11] = { opponent.position1, ..., opponent.position11 };
    
    // 2. 过滤：排除球后方的球员（无法射门）
    for (int i = 0; i < 11; i++) {
        if (cur_pos[i].x >= ball.position.x)
            cur_pos[i] = CPoint(-965, -723);  // 标记为无效位置
    }
    
    // 3. 计算距球最近的对方球员（最具威胁）
    int threat_id = 0;
    double min_distance = Distance(cur_pos[0], ball.position);
    for (int i = 1; i < 11; i++) {
        if (Distance(cur_pos[i], ball.position) < min_distance) {
            min_distance = Distance(cur_pos[i], ball.position);
            threat_id = i;
        }
    }
    
    return cur_pos[threat_id];  // 返回威胁球员位置
}
```

**威胁判定逻辑**：

- 只考虑球前方的对方球员（具备射门能力）
- 距离球越近 = 威胁越大
- 动态更新，每个周期重新评估

---

##### 1.3 位置预测算法

守门员采用**双模式预测**，根据球的运动状态选择最优预测方式：

###### 模式 1：轨迹预测（球在运动中）

当球速足够快且运动方向明确时，使用**线性轨迹外推法**：

```cpp
// 计算球门线（X=965）处的 Y 坐标预测值
double dy = ball.position.y - ball.oldPosition.y;
double dx = ball.position.x - ball.oldPosition.x;

// 直线方程：y = kx + b
// k = dy/dx, b = y0 - k*x0
int xii = (dy/dx) * 965 + (ball.oldPosition.y - (dy/dx) * ball.oldPosition.x);
```

**触发条件**：

- `Distance(ball.position, ball.oldPosition) >= 1`（球在移动）
- `ball.position.x > ball.oldPosition.x`（球朝向我方球门）
- `313 <= xii <= 505`（预测点在球门范围内）

###### 模式 2：威胁球员预测（球静止或预测失效）

当轨迹预测不可用时，基于**威胁球员与球的连线**预测射门方向：

```cpp
CPoint shooter = shooter_pos();  // 获取威胁球员位置

// 计算射门线与球门线的交点
double dy = ball.position.y - shooter.y;
double dx = ball.position.x - shooter.x;
int xii = (dy/dx) * 965 + (shooter.y - (dy/dx) * shooter.x);

if (xii < 313 || xii > 505) {
    // 预测点在球门外 → 使用加权中心法
    xiy = (Distance(ball, CPoint(863,313)) * 192 / 
           (Distance(ball, CPoint(863,313)) + Distance(ball, CPoint(863,505)))) + 313.5;
}
```

**加权中心法**：当射门线不经过球门时，守门员站在距两个球门柱加权距离的中心点，覆盖更大角度。

---

##### 1.4 站位策略

###### X 轴站位（深度控制）

```cpp
int xix = ball.position.x > 950 ? 965 : 950;  // 基础位置
int xid = 2;  // 前移补偿量

if (预测 Y 坐标 < 343 || 预测 Y 坐标 > 475) {
    xix = 965;  // 靠近球门线（覆盖球门角）
}
else {
    xix = 950;  // 前移至 950（扩大防守范围）
}
```

**深度分层**：

- **965**（球门线）：当球朝向球门角时，紧贴球门线防守
- **950**（前置位置）：当球朝向球门中部时，前移扩大拦截范围
- **动态调整**：根据预测点实时切换

###### Y 轴站位（横向覆盖）

```cpp
// 轨迹预测模式
xiy = (dy/dx) * (xix - xid) + (ball.oldPosition.y - (dy/dx) * ball.oldPosition.x);

// 威胁球员预测模式
xiy = (dy/dx) * (xix - xid) + (shooter.y - (dy/dx) * shooter.x);

// 边界限制
xiy = max(313, min(505, xiy));  // 限制在球门范围内
```

###### 小范围晃动（迷惑对手）

当球在远端且未形成直接威胁时，守门员会在门线中心小范围左右晃动：

```cpp
if (ball.position.x <= 900 || ball.position.y < 313 || ball.position.y > 505) {
    if ((T / 4) % 2)  // 每 4 个周期切换一次
        xiy += 30;     // 向下晃动
    else
        xiy -= 30;     // 向上晃动
}
```

**晃动效果**：

- 防止守门员静止（避免被定点打击）
- 增加对方射门难度（动态目标更难瞄准）
- 保持反应活性（更快响应突发威胁）

---

##### 1.5 运动控制

守门员使用 `Direction()` 函数进行位置移动，该函数实现了 **PD 控制器**：

```cpp
void CStrategySystem::Direction(int which, CPoint point) {
    // 1. 计算目标点（延长线策略，增强响应性）
    point.x = 2 * point.x - robot->position.x;
    point.y = 2 * point.y - robot->position.y;
    
    // 2. 边界限制
    point = 限制在场地范围内;
    
    // 3. 计算位置误差和角度误差
    dx = point.x - robot->position.x;
    dy = point.y - robot->position.y;
    distance_e = sqrt(dx² + dy²);
    desired_angle = atan2(dy, dx) * 180/π;
    theta_e = desired_angle - robot->angle;
    
    // 4. PD 控制器计算轮速
    vL = 5.0 * (0.1 * distance_e + 0.444 * theta_e);
    vR = 5.0 * (0.1 * distance_e - 0.444 * theta_e);
    
    // 5. 发送速度命令
    Velocity(which, vL, vR);
}
```

**控制参数**：

- **比例系数（距离）**：0.1 → 距离越远，速度越快
- **比例系数（角度）**：0.444 → 角度偏差越大，转向越急
- **放大系数**：5.0 → 整体速度放大

---

##### 1.6 特殊情况处理

###### 球在守门员前方

```cpp
if (ball.position.x > hgoalie.position.x) {
    Stop(HGOALIE);  // 停止移动，节省能量，避免干扰队友
}
```

###### 预测失效保护

当多种预测模式都失效时（极端情况），守门员会回到球门中心待命：

```cpp
if (所有预测模式都失效) {
    xix = 965;
    xiy = 409;  // 球门中心 Y 坐标
}
```

---

##### 1.7 性能优化

**计算优化**：

- 使用整数运算替代浮点数（`int(计算结果 + 0.5)` 四舍五入）
- 缓存 `ball.oldPosition`，避免重复访问
- 仅在需要时计算 `shooter_pos()`（条件触发）

**响应优化**：

- 每个周期都执行（与其他策略并行）
- 无延迟决策（实时计算 → 立即执行）
- 双模式预测（确保始终有有效预测）

---

##### 1.8 技术亮点

1. **多模式融合**：轨迹预测 + 威胁球员预测，相互补充
2. **分层站位**：X 轴深度 + Y 轴横向，二维优化
3. **动态晃动**：小范围随机移动，增加防守不确定性
4. **智能过滤**：仅跟踪球后方的威胁球员，避免误判
5. **PD 控制**：平滑运动，避免抖动和过冲
6. **边界保护**：所有计算结果都经过边界检查，确保合法性

---

#### 2. 控球策略（Possession）

控球策略是最复杂的模块，采用**动态阵型系统**，根据球场位置自动选择最优阵型，并通过**智能分配算法**为每个球员分配位置。

##### 2.1 阵型系统（Formation System）

场地被划分为 **3×3 共 9 个区域**，每个区域对应特定阵型：

```text
场地分区（从我方门到对方门）：
┌─────────────┬─────────────┬─────────────┐
│ 阵型 1      │ 阵型 4      │ 阵型 7      │  Y < 217 (上区)
│ (左上防守)  │ (中上进攻)  │ (右上强攻)  │
├─────────────┼─────────────┼─────────────┤
│ 阵型 3      │ 阵型 6      │ 阵型 9      │  217-607 (中区)
│ (左中防守)  │ (中场过渡)  │ (右中强攻)  │
├─────────────┼─────────────┼─────────────┤
│ 阵型 2      │ 阵型 5      │ 阵型 8      │  Y > 607 (下区)
│ (左下防守)  │ (中下进攻)  │ (右下强攻)  │
└─────────────┴─────────────┴─────────────┘
   X < 290      290-740       X > 740
```

**阵型 ID 计算：**

```cpp
int CStrategySystem::fm_id() {
    if (ball.position.x < 290) {
        if (ball.position.y < 217) return 1;      // 左上
        else if (ball.position.y <= 607) return 3; // 左中
        else return 2;                             // 左下
    }
    else if (ball.position.x < 740) {
        if (ball.position.y < 217) return 4;      // 中上
        else if (ball.position.y <= 607) return 6; // 中中
        else return 5;                             // 中下
    }
    else {
        if (ball.position.y < 217) return 7;      // 右上
        else if (ball.position.y <= 607) return 9; // 右中
        else return 8;                             // 右下
    }
}
```

##### 2.2 中央球员选择（Central Player）

每个阵型都有一个**中央球员**（`cp_id()`），作为进攻核心，负责直接追球。其他球员围绕中央球员布阵。

**选择策略：**

- **进攻阵型（1, 2, 7, 8）**：选择距球最近且 Y 坐标符合条件的球员
- **中场阵型（4, 5, 6）**：选择距球最近且在球前方（X > ball.x）的球员
- **特殊区域**：禁区附近优先选择 Y 坐标最接近的球员

```cpp
int CStrategySystem::cp_id() {
    CPoint cur_pos[10] = { home1.position, ..., home10.position };
    
    if (fm_id() == 1) {  // 左上阵型
        // 过滤：只考虑 Y >= ball.position.y 的球员
        筛选符合条件的球员
        返回距离球最近的球员 ID
    }
    // 其他阵型类似逻辑...
}
```

##### 2.3 球员位置分配

采用**分层排序算法**（`fp_sort()`），为阵型球员分配位置：

1. **第一层**：按距中央球员的距离排序（找出最近的球员）
2. **第二层**：按相对角度排序（从上到下或从左到右）
3. **分配执行**：最近的球员分配到最近的阵型位置

##### 示例：阵型 6（中场阵型）

```cpp
if (fm_id() == 6) {
    Direction(cp_id(), ball.position);  // 中央球员直接追球
    
    // 定义阵型位置（极坐标方式）
    pos[1] = CPoint(ball.x + cos(-90°)*20, ball.y + sin(-90°)*20);
    pos[2] = CPoint(ball.x + cos(90°)*20,  ball.y + sin(90°)*20);
    pos[3] = CPoint(pos[0].x + cos(-45°)*40, pos[0].y + sin(-45°)*40);
    pos[4] = CPoint(pos[0].x + cos(0°)*40,   pos[0].y + sin(0°)*40);
    pos[5] = CPoint(pos[0].x + cos(45°)*40,  pos[0].y + sin(45°)*40);
    // ... 更多位置
    
    // 分层分配
    fp_sort(rp);           // 按距离排序所有球员
    fp_sort(rp, 0, 2);     // 前 2 个按角度排序
    Direction(rp[1].id, pos[1]);
    Direction(rp[2].id, pos[2]);
    // ... 分配其他位置
}
```

**典型阵型布局：**

- **阵型 1/2（左侧防守）**：层叠式防守，阵型球员分布在中央球员右侧和前方
- **阵型 4/5（中场过渡）**：扇形展开，保持传球路线
- **阵型 6（中场圆形）**：360° 圆形包围，适应任意方向进攻
- **阵型 7/8（右侧强攻）**：集中前压，形成射门威胁
- **阵型 9（禁区进攻）**：根据球的 Y 坐标调整上下侧重点

---

#### 3. 罚球策略（Penalty）

罚球策略采用**曲线行驶算法**，通过控制左右轮速差实现弧线射门。

**策略特点：**

- **随机性**：随机选择上路或下路射门（50% 概率）
- **两阶段控制**：
  1. **接近阶段**：直线冲向球（距离 > 21）
  2. **射门阶段**：曲线调整，对准球门角（距离 ≤ 21）

**曲线射门算法：**

```cpp
// 计算轨迹半径
double r = Distance(robot, ball) / (2 * sin(θ))

// 差速控制
int lw = r / (r + 6) * 127  // 内轮速度降低
Velocity(1, lw, 127)         // 左慢右快 → 右转
```

**目标点：**

- 上路：`(28, 313)` - 球门上角
- 下路：`(28, 505)` - 球门下角

---

#### 4. 射门控制（Shot）

射门系统包含多个重载函数，支持不同场景的射门需求。

##### 4.1 基础射门（`shot(int which)`）

自动选择最优射门角度，避开防守球员。

##### 4.2 定向射门（`shot(int which, CPoint t)`）

向指定目标点射门，用于传球或战术配合。

##### 4.3 直射控制（`shot1(int which, double o, CPoint t)`）

最底层的射门实现，精确控制射门参数。

**射门决策流程：**

1. 检查射门条件（`canshot()`）
2. 计算射门角度和力度
3. 调整机器人朝向
4. 执行加速冲刺

---

### 辅助算法

#### 运动控制

- **Direction(int which, CPoint point)**：朝向某点移动
- **Position(int which, CPoint point)**：精确移动到某点（PD 控制）
- **PositionSE(int which, CPoint point)**：不进禁区版本的 Position
- **Rush(int which, CPoint point)**：全速冲向某点
- **Velocity(int which, int vL, int vR)**：底层速度控制

#### 几何计算

- **Distance(CPoint p1, CPoint p2)**：两点间距离
- **Angle(CPoint p1, CPoint p2)**：两点间角度
- **atwo(...)**：计算两直线夹角

#### 场景检测

- **Status()**：判断比赛状态（罚球、争球、正常）
- **search1() / search2()**：搜索特定区域的机器人
- **shooter_pos()**：识别对方射门威胁球员

---

### 技术亮点

1. **自适应阵型系统**：根据球场 9 个区域自动切换 9 种阵型
2. **分层智能分配**：距离-角度二级排序，确保球员位置最优
3. **预测式防守**：守门员提前预判球路，而非被动反应
4. **禁区规避逻辑**：`PositionSE` 自动规避己方禁区，防止违规
5. **曲线行驶算法**：基于几何学的差速控制，实现精确弧线运动
6. **状态机架构**：清晰的策略切换逻辑，易于扩展和调试

---

### 性能特征

- **实时响应**：每个周期（约 100ms）完成一次决策
- **并发控制**：同时控制 11 个球员（10 个场上球员 + 1 个守门员）
- **鲁棒性**：支持球员丢失、通信延迟等异常情况
- **可扩展性**：模块化设计，可轻松添加新阵型和策略

## 📊 数据结构

### 机器人数据 (`Robot1`, `Robot2`, `Robot3`)

```cpp
struct Robot1 {
    int angle;              // 机器人角度
    CPoint position;        // 当前位置
    CPoint oldPosition;     // 历史位置
    BOOL bAlive;           // 存活状态
};
```

### 控制命令 (`CCommand`)

```cpp
union CCommand {
    BYTE Stream[3];
    struct tagData {
        char Lv;           // 左轮速度
        char Rv;           // 右轮速度
        char Command;      // 控制命令
    } Data;
};
```

## 🔧 配置说明

### 场地参数

- **场地尺寸**：参见 `docs/Field Coordinates.jpg`
- **坐标系统**：笛卡尔坐标系，原点位于场地中心
- **角度范围**：0-360°（顺时针）

### 通信协议

- **协议类型**：TCP/IP Socket
- **数据格式**：文本协议
- **默认端口**：5001

## 📄 许可证

本项目采用 **Noncommercial No-Derivatives Software License 1.0** 许可证。

- ✅ 允许非商业用途使用和复制
- ✅ 允许学术研究和教学
- ❌ 禁止商业使用
- ❌ 禁止分发修改版本

详细信息请参见 [LICENSE](LICENSE) 文件。

## 🤝 贡献

本项目目前暂不接受外部贡献。

## 🙏 致谢

感谢所有团队成员的辛勤付出，以及中国机器人大赛组委会提供的竞赛平台。

---

<div align="center">

**为 ATRI 加油！🏆**

*Made with ❤️ by ATRI Team*

</div>
