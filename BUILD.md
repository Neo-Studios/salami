# 🛠️ Building the Salami Application

This document provides comprehensive instructions for building and deploying the Salami WinUI 3 C++ application, including the office suite (SalamiWrite, SalamiCalc, SalamiSlides) and professional installer.

## Table of Contents

- [Prerequisites](#prerequisites)
- [Quick Start](#quick-start)
- [Detailed Build Instructions](#detailed-build-instructions)
- [Building the Installer](#building-the-installer)
- [Build Configurations](#build-configurations)
- [Troubleshooting](#troubleshooting)
- [Architecture Details](#architecture-details)

---

## Prerequisites

### Required Software

1. **Windows 10/11**
   - Windows 10 version 1809 (Build 17763) or higher
   - Windows 11 recommended for best experience

2. **Visual Studio 2022** (version 17.0 or later)
   - Download from: https://visualstudio.microsoft.com/vs/
   - **Required Workloads:**
     - ✅ Desktop development with C++
     - ✅ Universal Windows Platform development (optional, for UWP tools)
   - **Required Individual Components:**
     - ✅ Windows 11 SDK (10.0.22621.0 or later)
     - ✅ C++/WinRT
     - ✅ MSVC v143 - VS 2022 C++ x64/x86 build tools
     - ✅ C++ CMake tools for Windows (optional)

3. **Windows App SDK 1.4+**
   - Installed automatically via NuGet when building the project
   - Package: `Microsoft.WindowsAppSDK` version 1.4.231008000

4. **WiX Toolset 3.11+** (Optional - for building installer)
   - Download from: https://wixtoolset.org/
   - Required only if you want to create the MSI installer package
   - WiX Visual Studio extension recommended
   - **Note:** This project uses WiX 3.x syntax. WiX 4.x has breaking changes and requires migration

### NuGet Packages

The following packages are automatically restored during build:

- `Microsoft.WindowsAppSDK` (1.4.231008000)
- `Microsoft.Windows.CppWinRT` (2.0.230706.1)
- `Microsoft.Windows.SDK.BuildTools` (10.0.22621.755)

---

## Quick Start

### Clone and Build (5 minutes)

```bash
# 1. Clone the repository (replace with your actual repository URL)
git clone https://github.com/Neo-Studios/salami.git
cd salami

# 2. Open in Visual Studio 2022
start Salami.sln

# 3. Restore NuGet packages (automatic on first build)
# In Visual Studio: Right-click solution → "Restore NuGet Packages"

# 4. Build the solution
# Press Ctrl+Shift+B or select Build > Build Solution

# 5. Run the application
# Press F5 (Debug) or Ctrl+F5 (Release without debugging)
```

**Expected Build Time:** 
- First build: 2-5 minutes (includes NuGet restore)
- Incremental builds: 10-30 seconds

---

## Detailed Build Instructions

### Step 1: Environment Setup

#### Install Visual Studio 2022

1. Download Visual Studio 2022 Community, Professional, or Enterprise
2. Run the installer and select:
   - **Desktop development with C++** workload
   - Under "Installation details," ensure these are checked:
     - MSVC v143 C++ build tools
     - Windows 11 SDK (10.0.22621.0)
     - C++/WinRT
     - C++ ATL for latest build tools (optional)
     - C++ MFC for latest build tools (optional)

3. Complete the installation (requires ~10-15 GB disk space)

#### Verify Installation

```powershell
# Check Visual Studio version
"C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\devenv.exe" /?

# Check MSBuild
"C:\Program Files\Microsoft Visual Studio\2022\Community\MSBuild\Current\Bin\MSBuild.exe" -version
```

### Step 2: Clone the Repository

```bash
# Using HTTPS (replace with your actual repository URL)
git clone https://github.com/Neo-Studios/salami.git

# Or using SSH
git clone git@github.com:Neo-Studios/salami.git

# Navigate to the project
cd salami
```

### Step 3: Open the Solution

#### Option A: Visual Studio IDE

1. Double-click `Salami.sln` or
2. Open Visual Studio 2022
3. File → Open → Project/Solution
4. Navigate to `salami` folder and select `Salami.sln`

#### Option B: Command Line

```bash
start Salami.sln
```

### Step 4: Restore NuGet Packages

NuGet packages are automatically restored on the first build. To manually restore:

**In Visual Studio:**
- Right-click on the Solution in Solution Explorer
- Select "Restore NuGet Packages"

**Using Command Line:**
```bash
nuget restore Salami.sln
```

**Using MSBuild:**
```bash
msbuild Salami.sln -t:restore
```

### Step 5: Select Build Configuration

1. In Visual Studio toolbar, select:
   - **Configuration:** `Debug` or `Release`
   - **Platform:** `x64` (64-bit)

**Build Configurations:**
- **Debug|x64** - Development build with debugging symbols, unoptimized
- **Release|x64** - Production build with optimizations, smaller binary

### Step 6: Build the Solution

#### Using Visual Studio IDE

**Menu:**
- Build → Build Solution (Ctrl+Shift+B)

**Output:**
- Debug: `x64\Debug\Salami.exe`
- Release: `x64\Release\Salami.exe`

#### Using MSBuild Command Line

```bash
# Navigate to solution directory
cd C:\path\to\salami

# Build Debug configuration
msbuild Salami.sln -p:Configuration=Debug -p:Platform=x64

# Build Release configuration
msbuild Salami.sln -p:Configuration=Release -p:Platform=x64

# Clean and rebuild
msbuild Salami.sln -t:Rebuild -p:Configuration=Release -p:Platform=x64
```

#### Using Developer Command Prompt

```bash
# Open "Developer Command Prompt for VS 2022" from Start Menu

cd C:\path\to\salami
msbuild Salami.sln /m /p:Configuration=Release /p:Platform=x64
```

**MSBuild Options:**
- `/m` - Multi-processor build (faster)
- `/v:detailed` - Verbose output for debugging build issues
- `/t:Clean` - Clean build outputs
- `/t:Rebuild` - Clean and rebuild

### Step 7: Run the Application

#### From Visual Studio

- **Debug Mode:** Press F5 (launches with debugger attached)
- **Release Mode:** Press Ctrl+F5 (runs without debugger)

#### From Command Line

```bash
# Debug build
x64\Debug\Salami.exe

# Release build
x64\Release\Salami.exe
```

#### From File Explorer

Navigate to `x64\Debug` or `x64\Release` and double-click `Salami.exe`

---

## Building the Installer

The Salami application includes a professional WiX-based MSI installer for deployment.

### Prerequisites for Installer

1. **WiX Toolset 3.11 or later**
   - Download: https://wixtoolset.org/releases/
   - Install WiX Toolset build tools
   - Optionally install WiX Toolset Visual Studio Extension

2. **WiX Environment Variables**
   After installation, ensure these are in your PATH:
   - `candle.exe` - WiX compiler
   - `light.exe` - WiX linker

### Installer Build Steps

#### Step 1: Build the Application (Release)

```bash
# Build release version first
msbuild Salami.sln -p:Configuration=Release -p:Platform=x64
```

#### Step 2: Navigate to Installer Directory

```bash
cd Installer
```

#### Step 3: Compile WiX Source

```bash
# Compile Product.wxs to object file
candle Product.wxs -ext WixUIExtension -ext WixUtilExtension
```

**Output:** `Product.wixobj`

#### Step 4: Link and Create MSI

```bash
# Link object file to create MSI installer
light Product.wixobj -ext WixUIExtension -ext WixUtilExtension -out SalamiSetup.msi

# Note: Remove -sval flag if present; it suppresses validation and can hide issues
```

**Output:** `SalamiSetup.msi`

#### Complete Installer Build Script

```batch
@echo off
echo Building Salami Application...
cd ..
msbuild Salami.sln -p:Configuration=Release -p:Platform=x64 -m

echo.
echo Building Installer...
cd Installer
candle Product.wxs -ext WixUIExtension -ext WixUtilExtension
light Product.wixobj -ext WixUIExtension -ext WixUtilExtension -out SalamiSetup.msi

echo.
echo Build complete! Installer: Installer\SalamiSetup.msi
pause
```

Save this as `build-installer.bat` in the root directory.

### Installer Features

The MSI installer includes:

✅ **Main Application** (required)
- Core Salami application executable
- Windows App SDK runtime
- VC++ Runtime dependencies

✅ **Game Module** (optional)
- 5-level Salami Adventure 3D game
- Game assets and sprites

✅ **Salami Database** (optional)
- 20+ salami varieties with detailed information
- Recipe database
- Historical content

✅ **Documentation** (optional)
- README.md
- LICENSE
- User Guide
- Quick Start Guide

✅ **Installation Options**
- Desktop shortcut creation
- Start Menu shortcuts
- File association (.salami files)
- Registry keys for app configuration
- Automatic launch after installation

### Testing the Installer

```bash
# Install silently
msiexec /i SalamiSetup.msi /quiet

# Install with UI
msiexec /i SalamiSetup.msi

# Uninstall silently
msiexec /x SalamiSetup.msi /quiet

# Repair installation
msiexec /fa SalamiSetup.msi
```

---

## Build Configurations

### Debug Configuration

**Purpose:** Development and debugging

**Characteristics:**
- No optimizations (`/Od`)
- Full debug symbols (`/Zi`)
- Runtime checks enabled
- Larger binary size (~15-20 MB)
- Slower execution
- Includes debugging information

**Use when:**
- Developing new features
- Debugging issues
- Running in Visual Studio debugger

### Release Configuration

**Purpose:** Production deployment

**Characteristics:**
- Full optimizations (`/O2`)
- Minimal debug info
- Runtime checks disabled
- Smaller binary size (~8-12 MB)
- Faster execution
- Code optimization enabled

**Use when:**
- Creating installer packages
- Performance testing
- End-user deployment

### Configuration Properties

| Property | Debug | Release |
|----------|-------|---------|
| Optimization | Disabled | Maximum Speed |
| Debug Info | Full | Minimal |
| Inline Functions | Disabled | Enabled |
| Runtime Library | Multi-threaded Debug DLL | Multi-threaded DLL |
| Code Generation | /Od | /O2 |
| Preprocessor | DEBUG=1 | NDEBUG=1 |

---

## Troubleshooting

### Common Build Issues

#### Issue: "Windows App SDK not found"

**Solution:**
```bash
# Restore NuGet packages manually
nuget restore Salami.sln

# Or in Visual Studio
# Right-click Solution → Restore NuGet Packages
```

#### Issue: "Cannot open include file 'winrt/Windows.Foundation.h'"

**Cause:** C++/WinRT headers not generated or NuGet packages not restored

**Solution:**
1. Clean the solution: Build → Clean Solution
2. Restore NuGet packages: Right-click Solution → Restore NuGet Packages
3. Rebuild: Build → Rebuild Solution
4. If issue persists, delete bin/ and obj/ folders and rebuild

#### Issue: "MSB8036: The Windows SDK version was not found"

**Solution:**
- Install Windows 11 SDK (10.0.22621.0) via Visual Studio Installer
- Or update `Salami.vcxproj` to use your installed SDK version

#### Issue: "LNK2001: unresolved external symbol"

**Cause:** Missing library or incorrect configuration

**Solution:**
- Ensure Platform is set to x64 (not x86 or ARM64)
- Clean and rebuild solution
- Check that all NuGet packages restored successfully

#### Issue: Build succeeds but app won't start

**Symptoms:** Application closes immediately or shows error dialog

**Solution:**
1. **Check Windows version:** Must be Windows 10 1809+
2. **Install Windows App SDK Runtime:**
   - Download from: https://learn.microsoft.com/windows/apps/windows-app-sdk/downloads
3. **Run from Visual Studio** (F5) to see error messages
4. **Check Event Viewer:** Windows Logs → Application

#### Issue: WiX build fails with "The system cannot find the file referenced"

**Cause:** Application not built before installer, or incorrect paths in WiX configuration

**Solution:**
1. Build Release configuration first
2. Verify `x64\Release\Salami.exe` exists
3. Check file paths in `Product.wxs`
4. Ensure all referenced files exist

### Performance Issues

#### Slow Build Times

**Solutions:**
- Enable multi-processor build: Tools → Options → Projects and Solutions → Build and Run → "maximum number of parallel project builds"
- Use `/m` flag with MSBuild
- Disable antivirus scanning for project folder
- Build on SSD instead of HDD
- Close other applications during build

#### High Memory Usage During Build

**Solutions:**
- Close other Visual Studio instances
- Disable parallel builds temporarily
- Increase system page file size
- Use command-line MSBuild instead of Visual Studio

### Getting Help

If you encounter issues not covered here:

1. **Check build output:** View → Output (Ctrl+Alt+O)
2. **Check error list:** View → Error List
3. **Enable verbose logging:**
   ```bash
   msbuild Salami.sln /v:detailed > build.log 2>&1
   ```
4. **Search existing issues:** Check repository issues for similar problems
5. **Create an issue:** Report build problems with logs and environment details

---

## Architecture Details

### Project Structure

```
Salami/
├── Salami.sln                          # Visual Studio Solution
├── Salami.vcxproj                      # C++ Project Configuration
├── packages.config                     # NuGet Package Dependencies
│
├── Core Application Files
│   ├── App.xaml[.h/.cpp]              # Application Entry Point
│   ├── MainWindow.xaml[.h/.cpp]       # Main Navigation Window
│   ├── pch.h / pch.cpp                # Precompiled Headers
│   └── Package.appxmanifest           # App Manifest
│
├── Data Layer (1,381 lines)
│   ├── Models.h                        # Data Structures (154 lines)
│   ├── SalamiDatabase.h               # Database Interface
│   ├── SalamiDatabase.cpp             # Database Implementation (1,227 lines)
│   └── GameEngine.h                   # Game Entity System (423 lines)
│
├── Content Pages (~3,500 lines)
│   ├── HomePage.xaml[.h/.cpp]         # Welcome Page
│   ├── GalleryPage.xaml[.h/.cpp]      # 20+ Salami Varieties
│   ├── HistoryPage.xaml[.h/.cpp]      # Historical Timeline
│   ├── RecipesPage.xaml[.h/.cpp]      # 10+ Recipes
│   ├── ProductionPage.xaml[.h/.cpp]   # 7-Step Production Guide
│   ├── PairingPage.xaml[.h/.cpp]      # Pairing Recommendations
│   ├── FunFactsPage.xaml[.h/.cpp]     # 50+ Fun Facts
│   └── SettingsPage.xaml[.h/.cpp]     # App Settings
│
├── Game System (~1,700 lines)
│   └── GamePage.xaml[.h/.cpp]         # 5-Level Adventure Game
│
├── Productivity Suite (~3,600 lines)
│   ├── CalendarPage.xaml[.h/.cpp]     # Calendar/Planner (546 lines)
│   ├── NotesPage.xaml[.h/.cpp]        # Notes App (581 lines)
│   ├── WordProcessorPage.xaml[.h/.cpp]# SalamiWrite (1,539 lines)
│   ├── SpreadsheetPage.xaml[.h/.cpp]  # SalamiCalc (1,131 lines)
│   └── PresentationPage.xaml[.h/.cpp] # SalamiSlides (1,336 lines)
│
└── Installer/
    └── Product.wxs                     # WiX Installer Config (320 lines)
```

### Technology Stack

| Component | Technology | Version |
|-----------|------------|---------|
| Language | C++ | C++20 |
| UI Framework | WinUI 3 | 1.4+ |
| Platform | Windows | 10/11 |
| App SDK | Windows App SDK | 1.4.231008000 |
| C++/WinRT | Microsoft.Windows.CppWinRT | 2.0.230706.1 |
| Build Tools | MSBuild | 17.0+ |
| IDE | Visual Studio | 2022 |
| Installer | WiX Toolset | 3.11+ |

### Build Outputs

**Debug Build:**
```
x64/Debug/
├── Salami.exe              # Main executable (~15-20 MB)
├── Salami.pdb              # Debug symbols
├── Microsoft.WindowsAppRuntime.*.dll
├── Microsoft.ui.xaml.dll
└── resources.pri           # Packaged resources
```

**Release Build:**
```
x64/Release/
├── Salami.exe              # Optimized executable (~8-12 MB)
├── Microsoft.WindowsAppRuntime.*.dll
├── Microsoft.ui.xaml.dll
└── resources.pri
```

### Code Statistics

| Category | Lines | Files |
|----------|-------|-------|
| **Total** | **11,376+** | **52+** |
| Core Application | ~2,100 | 10 |
| Content Pages | ~3,500 | 24 |
| Game System | ~2,100 | 3 |
| Productivity Suite | ~3,300 | 15 |
| Installer | 320 | 1 |

---

## Advanced Build Options

### Build from PowerShell

```powershell
# Set up Visual Studio environment
& "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\Launch-VsDevShell.ps1"

# Navigate to project
cd C:\path\to\salami

# Build
msbuild Salami.sln -p:Configuration=Release -p:Platform=x64 -m

# Run
& "x64\Release\Salami.exe"
```

### Continuous Integration (CI) Build

```yaml
# Example GitHub Actions workflow
- name: Setup MSBuild
  uses: microsoft/setup-msbuild@v1

- name: Restore NuGet
  run: nuget restore Salami.sln

- name: Build
  run: msbuild Salami.sln -p:Configuration=Release -p:Platform=x64 -m

- name: Upload Artifact
  uses: actions/upload-artifact@v2
  with:
    name: Salami-Release
    path: x64/Release/
```

### Custom Build Targets

Add to `Salami.vcxproj` for custom build steps:

```xml
<Target Name="PostBuildCopy" AfterTargets="Build">
  <Copy SourceFiles="@(RuntimeDependencies)" 
        DestinationFolder="$(OutDir)" />
</Target>
```

---

## Next Steps

After successfully building:

1. ✅ **Run the Application** - Press F5 in Visual Studio
2. ✅ **Explore Features** - Navigate through all 13+ pages
3. ✅ **Try the Game** - Play Salami Adventure 3D with 5 levels
4. ✅ **Use Office Suite** - Test SalamiWrite, SalamiCalc, SalamiSlides
5. ✅ **Build Installer** - Create MSI for deployment
6. ✅ **Distribute** - Share your love of salami!

---

## Additional Resources

- **WinUI 3 Documentation:** https://learn.microsoft.com/windows/apps/winui/
- **C++/WinRT Guide:** https://learn.microsoft.com/windows/uwp/cpp-and-winrt-apis/
- **Windows App SDK:** https://learn.microsoft.com/windows/apps/windows-app-sdk/
- **WiX Toolset:** https://wixtoolset.org/documentation/
- **Visual Studio C++:** https://learn.microsoft.com/cpp/

---

**Built with ❤️ for salami enthusiasts everywhere! 🍖**
