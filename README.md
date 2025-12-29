# 🍖 Salami - A Celebration of Excellence

A WinUI 3 C++ application dedicated to celebrating salami - the art, tradition, and incredible taste of this magnificent cured meat.

## Overview

This application is all about salami. Just salami. No food delivery, no random facts, no distractions. Pure salami appreciation featuring:

- **Home Page**: Welcome to salami central with an overview of what makes salami amazing
- **Gallery**: Explore stunning varieties of salami from around the world (Italian, Spanish, French, German)
- **History**: Discover the rich heritage and tradition of salami making through the ages
- **Recipes**: Delicious ways to enjoy salami in your meals with detailed cooking instructions
- **Settings**: Customize your salami appreciation experience with themes, preferences, and notifications

## Features

✨ **Beautiful WinUI 3 Interface**: Modern, responsive design with navigation
🌍 **International Salami Varieties**: Learn about salamis from Italy, Spain, France, and Germany
📚 **Rich Historical Content**: Explore centuries of salami-making tradition
👨‍🍳 **Delicious Recipes**: Four amazing recipes featuring salami
⚙️ **Customizable Settings**: Personalize your experience with themes and preferences
🎨 **Salami-themed Colors**: Custom color scheme inspired by salami

## Requirements

- Windows 10 version 1809 (Build 17763) or higher
- Windows 11 recommended
- Visual Studio 2022 (version 17.0 or later) with:
  - Desktop development with C++ workload
  - Windows App SDK
  - C++/WinRT extensions

## Building the Application

### Prerequisites

1. Install [Visual Studio 2022](https://visualstudio.microsoft.com/vs/) with:
   - Desktop development with C++
   - Windows 11 SDK (10.0.22621.0 or later)
   - Windows App SDK (1.4 or later)

2. Install the C++/WinRT Visual Studio Extension (VSIX)

### Build Steps

1. Clone the repository:
   ```bash
   git clone https://github.com/Neo-Studios/salami.git
   cd salami
   ```

2. Open the solution:
   ```bash
   Salami.sln
   ```

3. Restore NuGet packages:
   - Right-click on the solution in Solution Explorer
   - Select "Restore NuGet Packages"

4. Build the solution:
   - Select "Build > Build Solution" (Ctrl+Shift+B)
   - Or select "Debug > Start Debugging" (F5) to build and run

### Build Configuration

- **Debug**: Development build with debugging symbols
- **Release**: Optimized production build
- **Platform**: x64 (64-bit Windows)

## Running the Application

After building, you can run the application by:

1. Pressing F5 in Visual Studio (Debug mode)
2. Pressing Ctrl+F5 (Run without debugging)
3. Running the executable from: `x64\Debug\Salami.exe` or `x64\Release\Salami.exe`

## Project Structure

```
Salami/
├── Salami.sln              # Visual Studio solution file
└── Salami/                 # Main project directory
    ├── Salami.vcxproj      # Visual C++ project file
    ├── packages.config     # NuGet packages configuration
    ├── Package.appxmanifest # Windows app manifest
    ├── pch.h / pch.cpp     # Precompiled headers
    ├── App.xaml            # Application definition (XAML)
    ├── App.xaml.h/cpp      # Application implementation
    ├── MainWindow.xaml     # Main window with navigation
    ├── MainWindow.xaml.h/cpp
    ├── HomePage.xaml       # Home page content
    ├── HomePage.xaml.h/cpp
    ├── GalleryPage.xaml    # Salami varieties gallery
    ├── GalleryPage.xaml.h/cpp
    ├── HistoryPage.xaml    # History of salami
    ├── HistoryPage.xaml.h/cpp
    ├── RecipesPage.xaml    # Salami recipes
    ├── RecipesPage.xaml.h/cpp
    ├── SettingsPage.xaml   # App settings
    └── SettingsPage.xaml.h/cpp
```

## Technologies Used

- **Language**: C++20
- **UI Framework**: WinUI 3 (Windows App SDK)
- **Platform**: Windows 10/11
- **Architecture**: Modern C++/WinRT
- **Build System**: MSBuild (Visual Studio)

## Contributing

This is a salami appreciation project. Contributions should maintain focus on salami and its celebration. No food delivery features, no unrelated content - just salami!

## License

This project is dedicated to the appreciation of salami.

## About

Created with ❤️ for salami lovers everywhere. Because salami deserves its own dedicated application.

---

**Remember**: This app is about salami, and salami alone. No distractions, no alternatives, just pure salami excellence! 🍖