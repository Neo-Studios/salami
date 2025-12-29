#include "pch.h"
#include "GamePage.xaml.h"
#if __has_include("GamePage.g.cpp")
#include "GamePage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Windows::System;

namespace winrt::Salami::implementation
{
    GamePage::GamePage()
    {
        InitializeComponent();
        InitializeGame();
    }

    GamePage::~GamePage()
    {
        if (m_gameTimer)
        {
            m_gameTimer.Stop();
        }
        if (m_animationTimer)
        {
            m_animationTimer.Stop();
        }
        
        // Unregister event handlers
        if (m_keyDownToken)
        {
            Window::Current().Content().as<UIElement>().KeyDown(m_keyDownToken);
        }
        if (m_keyUpToken)
        {
            Window::Current().Content().as<UIElement>().KeyUp(m_keyUpToken);
        }
    }

    void GamePage::InitializeGame()
    {
        // Initialize game timer (updates every 16ms for ~60 FPS)
        m_gameTimer = DispatcherTimer();
        m_gameTimer.Interval(std::chrono::milliseconds(16));
        m_gameTimer.Tick([this](auto&&, auto&&)
        {
            UpdateGame();
        });

        // Initialize animation timer (for visuals like powerup rotation)
        m_animationTimer = DispatcherTimer();
        m_animationTimer.Interval(std::chrono::milliseconds(50));
        m_animationTimer.Tick([this](auto&&, auto&&)
        {
            UpdateAnimations();
        });
        m_animationTimer.Start();

        // Register keyboard event handlers
        auto content = Window::Current().Content().as<UIElement>();
        m_keyDownToken = content.KeyDown({ this, &GamePage::OnKeyDown });
        m_keyUpToken = content.KeyUp({ this, &GamePage::OnKeyUp });

        ResetGame();
    }

    void GamePage::StartButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        StartGame();
    }

    void GamePage::PauseButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        PauseGame();
    }

    void GamePage::ResetButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        ResetGame();
    }

    void GamePage::RestartButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        GameOverOverlay().Visibility(Visibility::Collapsed);
        ResetGame();
        StartGame();
    }

    void GamePage::StartGame()
    {
        if (!m_gameRunning)
        {
            m_gameRunning = true;
            m_gamePaused = false;
            m_gameTimer.Start();
            
            StartButton().IsEnabled(false);
            PauseButton().IsEnabled(true);
            
            // Start timer countdown
            DispatcherTimer timerTick;
            timerTick.Interval(std::chrono::seconds(1));
            timerTick.Tick([this](auto&&, auto&&)
            {
                UpdateTimer();
            });
            timerTick.Start();
        }
    }

    void GamePage::PauseGame()
    {
        if (m_gameRunning && !m_gamePaused)
        {
            m_gamePaused = true;
            m_gameTimer.Stop();
            PauseButton().Content(box_value(L"▶️ Resume"));
        }
        else if (m_gameRunning && m_gamePaused)
        {
            m_gamePaused = false;
            m_gameTimer.Start();
            PauseButton().Content(box_value(L"⏸️ Pause"));
        }
    }

    void GamePage::ResetGame()
    {
        m_gameRunning = false;
        m_gamePaused = false;
        m_score = 0;
        m_cheeseCollected = 0;
        m_elapsedSeconds = 0;
        m_playerX = 375.0;
        m_playerY = 400.0;

        // Reset UI
        ScoreText().Text(L"0");
        CheeseCountText().Text(L"0/4");
        TimerText().Text(L"0:00");
        
        StartButton().IsEnabled(true);
        PauseButton().IsEnabled(false);
        PauseButton().Content(box_value(L"⏸️ Pause"));
        
        GameOverOverlay().Visibility(Visibility::Collapsed);

        // Reset player position
        Canvas::SetLeft(PlayerCanvas(), m_playerX);
        Canvas::SetTop(PlayerCanvas(), m_playerY);

        // Reset input states
        m_wPressed = false;
        m_sPressed = false;
        m_aPressed = false;
        m_dPressed = false;

        if (m_gameTimer)
        {
            m_gameTimer.Stop();
        }
    }

    void GamePage::UpdateGame()
    {
        if (!m_gameRunning || m_gamePaused)
            return;

        UpdatePlayerPosition();
        CheckCollisions();
        CheckGoalReached();
    }

    void GamePage::UpdatePlayerPosition()
    {
        double newX = m_playerX;
        double newY = m_playerY;

        // Update position based on input
        if (m_wPressed)
        {
            newY -= m_playerSpeed;
        }
        if (m_sPressed)
        {
            newY += m_playerSpeed;
        }
        if (m_aPressed)
        {
            newX -= m_playerSpeed;
        }
        if (m_dPressed)
        {
            newX += m_playerSpeed;
        }

        // Boundary checking
        if (newX < 0) newX = 0;
        if (newX > 760) newX = 760;
        if (newY < 0) newY = 0;
        if (newY > 520) newY = 520;

        // Update position
        m_playerX = newX;
        m_playerY = newY;

        Canvas::SetLeft(PlayerCanvas(), m_playerX);
        Canvas::SetTop(PlayerCanvas(), m_playerY);

        // Animate walking
        if (m_wPressed || m_sPressed || m_aPressed || m_dPressed)
        {
            m_animationFrame += 0.3;
            double legAngle = std::sin(m_animationFrame) * 20.0;
            double armAngle = std::sin(m_animationFrame) * 15.0;

            LeftLegRotation().Angle(legAngle);
            RightLegRotation().Angle(-legAngle);
            LeftArmRotation().Angle(-30 + armAngle);
            RightArmRotation().Angle(30 - armAngle);
        }
        else
        {
            LeftLegRotation().Angle(0);
            RightLegRotation().Angle(0);
            LeftArmRotation().Angle(-30);
            RightArmRotation().Angle(30);
        }
    }

    void GamePage::UpdateAnimations()
    {
        // Rotate powerup
        m_powerupRotation += 5.0;
        if (m_powerupRotation >= 360.0)
            m_powerupRotation = 0.0;
        
        PowerupRotation().Angle(m_powerupRotation);
    }

    void GamePage::CheckCollisions()
    {
        // Simple collision detection with collectibles
        // Check cheese pieces (simplified - would need actual positions)
        if (m_cheeseCollected < 4)
        {
            // Collision detection logic here
            // For demo purposes, we'll simulate collection based on position
            if (std::abs(m_playerX - 120) < 40 && std::abs(m_playerY - 350) < 40 && m_cheeseCollected == 0)
            {
                CollectCheese(0);
            }
            else if (std::abs(m_playerX - 300) < 40 && std::abs(m_playerY - 320) < 40 && m_cheeseCollected == 1)
            {
                CollectCheese(1);
            }
            else if (std::abs(m_playerX - 480) < 40 && std::abs(m_playerY - 380) < 40 && m_cheeseCollected == 2)
            {
                CollectCheese(2);
            }
            else if (std::abs(m_playerX - 620) < 40 && std::abs(m_playerY - 340) < 40 && m_cheeseCollected == 3)
            {
                CollectCheese(3);
            }
        }

        // Check collision with obstacles (hanging salamis)
        // Simplified collision detection
        struct Obstacle
        {
            double x, y, width, height;
        };

        Obstacle obstacles[] = {
            {150, 100, 40, 100},
            {350, 150, 50, 120},
            {550, 80, 45, 110},
            {250, 200, 35, 90},
            {450, 120, 42, 105},
            {650, 180, 38, 95}
        };

        for (const auto& obs : obstacles)
        {
            if (m_playerX + 40 > obs.x && m_playerX < obs.x + obs.width &&
                m_playerY + 80 > obs.y && m_playerY < obs.y + obs.height)
            {
                // Collision with obstacle - reduce score
                UpdateScore(-50);
                
                // Push player back
                if (m_wPressed) m_playerY += m_playerSpeed * 2;
                if (m_sPressed) m_playerY -= m_playerSpeed * 2;
                if (m_aPressed) m_playerX += m_playerSpeed * 2;
                if (m_dPressed) m_playerX -= m_playerSpeed * 2;
                
                Canvas::SetLeft(PlayerCanvas(), m_playerX);
                Canvas::SetTop(PlayerCanvas(), m_playerY);
            }
        }
    }

    void GamePage::CheckGoalReached()
    {
        // Check if player reached the goal (top-right area)
        if (m_playerX > 650 && m_playerY < 100)
        {
            if (m_cheeseCollected >= 4)
            {
                // Victory!
                GameOver(true);
            }
        }
    }

    void GamePage::CollectCheese(int index)
    {
        m_cheeseCollected++;
        UpdateScore(100);
        
        // Update cheese counter
        CheeseCountText().Text(std::to_wstring(m_cheeseCollected) + L"/4");
        
        // TODO: Hide the collected cheese visual
    }

    void GamePage::GameOver(bool won)
    {
        m_gameRunning = false;
        m_gameTimer.Stop();
        
        if (won)
        {
            GameOverTitle().Text(L"🎉 VICTORY!");
            
            // Bonus points for remaining time
            int timeBonus = std::max(0, (180 - m_elapsedSeconds) * 10);
            UpdateScore(timeBonus);
        }
        else
        {
            GameOverTitle().Text(L"💥 GAME OVER");
        }
        
        FinalScoreText().Text(L"Final Score: " + std::to_wstring(m_score));
        
        int minutes = m_elapsedSeconds / 60;
        int seconds = m_elapsedSeconds % 60;
        wchar_t timeStr[32];
        swprintf_s(timeStr, L"Time: %d:%02d", minutes, seconds);
        FinalTimeText().Text(timeStr);
        
        GameOverOverlay().Visibility(Visibility::Visible);
    }

    void GamePage::UpdateScore(int points)
    {
        m_score += points;
        if (m_score < 0) m_score = 0;
        
        ScoreText().Text(std::to_wstring(m_score));
    }

    void GamePage::UpdateTimer()
    {
        if (!m_gameRunning || m_gamePaused)
            return;

        m_elapsedSeconds++;
        
        int minutes = m_elapsedSeconds / 60;
        int seconds = m_elapsedSeconds % 60;
        
        wchar_t timeStr[32];
        swprintf_s(timeStr, L"%d:%02d", minutes, seconds);
        TimerText().Text(timeStr);
        
        // Game time limit (optional)
        if (m_elapsedSeconds >= 300) // 5 minutes
        {
            GameOver(false);
        }
    }

    void GamePage::OnKeyDown(IInspectable const&, Microsoft::UI::Xaml::Input::KeyRoutedEventArgs const& e)
    {
        auto key = e.Key();
        
        if (key == VirtualKey::W || key == VirtualKey::Up)
        {
            m_wPressed = true;
            e.Handled(true);
        }
        else if (key == VirtualKey::S || key == VirtualKey::Down)
        {
            m_sPressed = true;
            e.Handled(true);
        }
        else if (key == VirtualKey::A || key == VirtualKey::Left)
        {
            m_aPressed = true;
            e.Handled(true);
        }
        else if (key == VirtualKey::D || key == VirtualKey::Right)
        {
            m_dPressed = true;
            e.Handled(true);
        }
        else if (key == VirtualKey::Space)
        {
            if (!m_gameRunning)
            {
                StartGame();
            }
            else
            {
                PauseGame();
            }
            e.Handled(true);
        }
    }

    void GamePage::OnKeyUp(IInspectable const&, Microsoft::UI::Xaml::Input::KeyRoutedEventArgs const& e)
    {
        auto key = e.Key();
        
        if (key == VirtualKey::W || key == VirtualKey::Up)
        {
            m_wPressed = false;
            e.Handled(true);
        }
        else if (key == VirtualKey::S || key == VirtualKey::Down)
        {
            m_sPressed = false;
            e.Handled(true);
        }
        else if (key == VirtualKey::A || key == VirtualKey::Left)
        {
            m_aPressed = false;
            e.Handled(true);
        }
        else if (key == VirtualKey::D || key == VirtualKey::Right)
        {
            m_dPressed = false;
            e.Handled(true);
        }
    }
}
