#pragma once

#include "GamePage.g.h"
#include <winrt/Windows.System.h>
#include <winrt/Windows.UI.Core.h>

namespace winrt::Salami::implementation
{
    struct GamePage : GamePageT<GamePage>
    {
        GamePage();
        ~GamePage();

        void StartButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void PauseButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void ResetButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void RestartButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);

    private:
        // Game state
        bool m_gameRunning = false;
        bool m_gamePaused = false;
        int m_score = 0;
        int m_cheeseCollected = 0;
        double m_playerX = 375.0;
        double m_playerY = 400.0;
        double m_playerSpeed = 5.0;
        
        // Timer
        winrt::Microsoft::UI::Xaml::DispatcherTimer m_gameTimer{ nullptr };
        winrt::Microsoft::UI::Xaml::DispatcherTimer m_animationTimer{ nullptr };
        int m_elapsedSeconds = 0;
        
        // Animation
        double m_animationFrame = 0.0;
        double m_powerupRotation = 0.0;
        
        // Input tracking
        bool m_wPressed = false;
        bool m_sPressed = false;
        bool m_aPressed = false;
        bool m_dPressed = false;
        
        // Event tokens
        winrt::event_token m_keyDownToken;
        winrt::event_token m_keyUpToken;
        
        // Game methods
        void InitializeGame();
        void StartGame();
        void PauseGame();
        void ResetGame();
        void UpdateGame();
        void UpdatePlayerPosition();
        void UpdateAnimations();
        void CheckCollisions();
        void CheckGoalReached();
        void CollectCheese(int index);
        void GameOver(bool won);
        void UpdateScore(int points);
        void UpdateTimer();
        
        // Input handlers
        void OnKeyDown(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::KeyRoutedEventArgs const& e);
        void OnKeyUp(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::KeyRoutedEventArgs const& e);
    };
}

namespace winrt::Salami::factory_implementation
{
    struct GamePage : GamePageT<GamePage, implementation::GamePage>
    {
    };
}
