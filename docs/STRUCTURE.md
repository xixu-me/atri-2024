# ATRI-2024 Repository Structure

This document describes the reorganized file structure for the ATRI-2024 FIRA SimuroSot 11vs11 client repository.

## Directory Structure

```
ATRI-2024/
├── src/                          # Source code files (.cpp)
│   ├── Agentsock.cpp            # Socket communication implementation
│   ├── BaseAgent.cpp            # Base agent class implementation
│   ├── DSetupDlg.cpp            # Setup dialog implementation
│   ├── MainFrm.cpp              # Main frame window implementation
│   ├── MicroClient.cpp          # Main application implementation
│   ├── MicroClientDoc.cpp       # Document class implementation
│   ├── MicroClientView.cpp      # View class implementation
│   ├── StdAfx.cpp               # Precompiled header source
│   ├── StrategySystem.cpp       # Core strategy system implementation
│   └── TParseString.cpp         # String parsing utilities
│
├── include/                      # Header files (.h)
│   ├── Agentsock.h              # Socket communication interface
│   ├── BaseAgent.h              # Base agent class interface
│   ├── DSetupDlg.h              # Setup dialog interface
│   ├── General.h                # General definitions and structures
│   ├── MainFrm.h                # Main frame window interface
│   ├── MicroClient.h            # Main application interface
│   ├── MicroClientDoc.h         # Document class interface
│   ├── MicroClientView.h        # View class interface
│   ├── Resource.h               # Resource IDs
│   ├── StdAfx.h                 # Precompiled header
│   ├── StrategySystem.h         # Strategy system interface
│   └── TParseString.h           # String parsing utilities interface
│
├── res/                          # Resource files
│   ├── MicroClient.ico          # Application icon
│   ├── MicroClient.rc2          # Additional resources
│   ├── MicroClientDoc.ico       # Document icon
│   └── Toolbar.bmp              # Toolbar bitmap
│
├── docs/                         # Documentation
│   ├── Contest-Rules-2024.pdf   # Competition rules
│   └── Field Coordinates.jpg    # Field coordinate system reference
│
├── MicroClient.sln              # Visual Studio solution file
├── MicroClient.vcxproj          # Visual Studio project file (VS 2010+)
├── MicroClient.vcxproj.filters  # Project filters
├── MicroClient.rc               # Resource script
├── MicroClient.dsp              # Legacy project file (VS 6.0)
├── MicroClient.dsw              # Legacy workspace file (VS 6.0)
├── MicroClient.vcproj           # Legacy project file (VS 2008)
├── .gitignore                   # Git ignore rules
├── README.md                    # Main documentation (English)
└── LICENSE                      # License file

```

## Key Changes from Original Structure

### Organization

- **Source files** moved from root to `src/` directory
- **Header files** moved from root to `include/` directory  
- **Documentation** moved to `docs/` directory
- **Resources** reorganized in `res/` directory (lowercase)

### Project Configuration

- Updated `MicroClient.vcxproj` to reference new file locations
- Added `include` directory to Additional Include Directories
- Updated `MicroClient.vcxproj.filters` to match new structure

### New Files

- **README.md**: Comprehensive English documentation
- **.gitignore**: Excludes build artifacts and temporary files
- **docs/STRUCTURE.md**: This file - documents repository organization

### Removed from Git

Build artifacts and temporary files (via .gitignore):

- `*.suo`, `*.user` - User-specific Visual Studio files
- `*.aps`, `*.clw`, `*.ncb` - Build cache files
- `Debug/`, `Release/` - Build output directories

## Building the Project

The project can still be built using:

- **Visual Studio 2010 or later**: Open `MicroClient.sln`
- **Visual Studio 6.0** (legacy): Open `MicroClient.dsw`

The project files have been updated to automatically find source and header files in their new locations.

## Core Components

### Strategy System (`StrategySystem.cpp/h`)

Main decision-making logic for the robot team:

- Penalty kicks handling
- Free ball (争球) strategy
- Ball possession/offensive play
- Goalkeeper logic
- Dynamic formation management

### Agent System (`BaseAgent.cpp/h`, `Agentsock.cpp/h`)

Robot agent framework:

- Base agent class for robot behavior
- Socket communication with simulation server
- Real-time data exchange

### User Interface (`MicroClientView.cpp/h`, `MainFrm.cpp/h`)

MFC-based graphical interface:

- Game visualization
- Real-time monitoring
- Control panel

### Configuration (`DSetupDlg.cpp/h`)

Setup and configuration:

- Connection settings
- Team configuration
- Strategy parameters

## Development Guidelines

### Adding New Files

**Source files (.cpp)**:

- Place in `src/` directory
- Add to `MicroClient.vcxproj` under `<ItemGroup><ClCompile>`
- Add to `MicroClient.vcxproj.filters` under Source Files filter

**Header files (.h)**:

- Place in `include/` directory
- Add to `MicroClient.vcxproj` under `<ItemGroup><ClInclude>`
- Add to `MicroClient.vcxproj.filters` under Header Files filter
- Include in source files as: `#include "filename.h"` (include directory is in path)

**Resources**:

- Place in `res/` directory
- Reference in `MicroClient.rc` as needed

### Include Path

The `include/` directory is automatically added to the compiler's include path, so headers can be included directly:

```cpp
#include "StrategySystem.h"  // Not #include "include/StrategySystem.h"
```

## License

This project uses a custom Noncommercial No-Derivatives Software License (NCND-Software-1.0).

- ✅ Free for non-commercial use (education, research, personal)
- ✅ Can use and distribute unmodified code
- ❌ No commercial use allowed
- ❌ No distribution of modified versions

See [LICENSE](../LICENSE) file for complete terms.

## Team

Developed by ATRI (Ace Team of Robotics Intelligence) for the 2024 China Robot Competition & RoboCup China Open.

- Team Leader: @xixu-me
- Members: @XIAOLingQ, @Wx-debug, @moxun333, @song-yaya, @huaxiaoshi, @biqianq, @isWorldEdit
