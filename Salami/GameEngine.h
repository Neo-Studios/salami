#pragma once
#include <vector>
#include <string>

namespace Salami::Game
{
    // Game entities
    enum class EntityType
    {
        Player,
        Obstacle,
        Collectible,
        PowerUp,
        Enemy,
        Boss
    };

    enum class PowerUpType
    {
        SpeedBoost,
        Shield,
        DoublePoints,
        Invincibility,
        ExtraLife
    };

    enum class EnemyType
    {
        PatrolSalami,
        ChargingSalami,
        FlyingSalami,
        SpinningSalami
    };

    struct Vector2D
    {
        double x;
        double y;

        Vector2D() : x(0), y(0) {}
        Vector2D(double _x, double _y) : x(_x), y(_y) {}

        Vector2D operator+(const Vector2D& other) const { return Vector2D(x + other.x, y + other.y); }
        Vector2D operator-(const Vector2D& other) const { return Vector2D(x - other.x, y - other.y); }
        Vector2D operator*(double scalar) const { return Vector2D(x * scalar, y * scalar); }
        double Length() const { return std::sqrt(x * x + y * y); }
        Vector2D Normalize() const { double len = Length(); return len > 0 ? Vector2D(x / len, y / len) : Vector2D(); }
    };

    struct Rectangle
    {
        double x, y, width, height;

        bool Intersects(const Rectangle& other) const
        {
            return x < other.x + other.width &&
                   x + width > other.x &&
                   y < other.y + other.height &&
                   y + height > other.y;
        }

        bool Contains(double px, double py) const
        {
            return px >= x && px <= x + width && py >= y && py <= y + height;
        }
    };

    class GameEntity
    {
    public:
        Vector2D position;
        Vector2D velocity;
        Rectangle bounds;
        EntityType type;
        bool active;
        int health;

        GameEntity() : active(true), health(1) {}
        virtual ~GameEntity() = default;
        virtual void Update(double deltaTime) = 0;
        virtual Rectangle GetBounds() const { return Rectangle{ position.x, position.y, bounds.width, bounds.height }; }
    };

    class Player : public GameEntity
    {
    public:
        int score;
        int lives;
        double speed;
        bool hasShield;
        double shieldTimer;
        double invincibilityTimer;
        double speedBoostTimer;
        double doublePointsTimer;

        Player() : score(0), lives(3), speed(5.0), hasShield(false), 
                   shieldTimer(0), invincibilityTimer(0), speedBoostTimer(0), doublePointsTimer(0)
        {
            type = EntityType::Player;
            health = 3;
            bounds = Rectangle{ 0, 0, 40, 80 };
        }

        void Update(double deltaTime) override
        {
            position = position + velocity * deltaTime;
            
            // Update power-up timers
            if (shieldTimer > 0) shieldTimer -= deltaTime;
            else hasShield = false;
            
            if (invincibilityTimer > 0) invincibilityTimer -= deltaTime;
            if (speedBoostTimer > 0) speedBoostTimer -= deltaTime;
            if (doublePointsTimer > 0) doublePointsTimer -= deltaTime;
        }

        void ApplyPowerUp(PowerUpType powerUp)
        {
            switch (powerUp)
            {
            case PowerUpType::SpeedBoost:
                speedBoostTimer = 10.0;
                speed = 8.0;
                break;
            case PowerUpType::Shield:
                hasShield = true;
                shieldTimer = 15.0;
                break;
            case PowerUpType::DoublePoints:
                doublePointsTimer = 20.0;
                break;
            case PowerUpType::Invincibility:
                invincibilityTimer = 8.0;
                break;
            case PowerUpType::ExtraLife:
                lives++;
                break;
            }
        }

        bool IsInvulnerable() const
        {
            return hasShield || invincibilityTimer > 0;
        }
    };

    class Obstacle : public GameEntity
    {
    public:
        Obstacle(double x, double y, double w, double h)
        {
            position = Vector2D(x, y);
            bounds = Rectangle{ 0, 0, w, h };
            type = EntityType::Obstacle;
        }

        void Update(double deltaTime) override {}
    };

    class Collectible : public GameEntity
    {
    public:
        int pointValue;
        std::wstring name;

        Collectible(double x, double y, int points, const std::wstring& itemName)
            : pointValue(points), name(itemName)
        {
            position = Vector2D(x, y);
            bounds = Rectangle{ 0, 0, 30, 30 };
            type = EntityType::Collectible;
        }

        void Update(double deltaTime) override {}
    };

    class PowerUp : public GameEntity
    {
    public:
        PowerUpType powerUpType;

        PowerUp(double x, double y, PowerUpType type)
            : powerUpType(type)
        {
            position = Vector2D(x, y);
            bounds = Rectangle{ 0, 0, 35, 35 };
            this->type = EntityType::PowerUp;
        }

        void Update(double deltaTime) override {}
    };

    class Enemy : public GameEntity
    {
    public:
        EnemyType enemyType;
        Vector2D patrolStart;
        Vector2D patrolEnd;
        double patrolProgress;
        int damage;

        Enemy(double x, double y, EnemyType type)
            : enemyType(type), patrolProgress(0), damage(1)
        {
            position = Vector2D(x, y);
            bounds = Rectangle{ 0, 0, 50, 100 };
            this->type = EntityType::Enemy;
            health = 3;
        }

        void Update(double deltaTime) override
        {
            switch (enemyType)
            {
            case EnemyType::PatrolSalami:
                UpdatePatrol(deltaTime);
                break;
            case EnemyType::ChargingSalami:
                // Charging behavior handled by game logic
                break;
            case EnemyType::FlyingSalami:
                UpdateFlying(deltaTime);
                break;
            case EnemyType::SpinningSalami:
                UpdateSpinning(deltaTime);
                break;
            }
        }

    private:
        void UpdatePatrol(double deltaTime)
        {
            patrolProgress += deltaTime * 0.5;
            double t = (std::sin(patrolProgress) + 1.0) / 2.0;
            position = patrolStart + (patrolEnd - patrolStart) * t;
        }

        void UpdateFlying(double deltaTime)
        {
            position.y += std::sin(patrolProgress * 2) * 2;
            patrolProgress += deltaTime;
        }

        void UpdateSpinning(double deltaTime)
        {
            patrolProgress += deltaTime * 3;
        }
    };

    class Boss : public GameEntity
    {
    public:
        std::wstring name;
        int maxHealth;
        double attackCooldown;
        double attackTimer;
        int phase;

        Boss(const std::wstring& bossName, int hp)
            : name(bossName), maxHealth(hp), attackCooldown(3.0), attackTimer(0), phase(1)
        {
            position = Vector2D(400, 100);
            bounds = Rectangle{ 0, 0, 100, 200 };
            type = EntityType::Boss;
            health = hp;
        }

        void Update(double deltaTime) override
        {
            attackTimer -= deltaTime;
            if (attackTimer <= 0)
            {
                attackTimer = attackCooldown;
                // Trigger attack
            }

            // Phase transitions
            if (health < maxHealth * 0.66 && phase == 1)
            {
                phase = 2;
                attackCooldown = 2.0;
            }
            else if (health < maxHealth * 0.33 && phase == 2)
            {
                phase = 3;
                attackCooldown = 1.5;
            }
        }

        double GetHealthPercentage() const
        {
            return static_cast<double>(health) / maxHealth;
        }
    };

    struct GameLevel
    {
        int levelNumber;
        std::wstring name;
        std::wstring description;
        int targetScore;
        double timeLimit;
        std::vector<Obstacle> obstacles;
        std::vector<Collectible> collectibles;
        std::vector<PowerUp> powerUps;
        std::vector<Enemy> enemies;
        Boss* boss;

        GameLevel() : levelNumber(1), targetScore(0), timeLimit(180.0), boss(nullptr) {}
        ~GameLevel() { if (boss) delete boss; }
    };

    class GameState
    {
    public:
        Player player;
        GameLevel* currentLevel;
        int currentLevelNumber;
        double elapsedTime;
        bool isPaused;
        bool isGameOver;
        bool isVictory;
        int totalScore;
        int highScore;

        GameState() : currentLevel(nullptr), currentLevelNumber(1), elapsedTime(0),
                      isPaused(false), isGameOver(false), isVictory(false),
                      totalScore(0), highScore(0) {}

        void Reset()
        {
            player = Player();
            currentLevelNumber = 1;
            elapsedTime = 0;
            isPaused = false;
            isGameOver = false;
            isVictory = false;
            totalScore = 0;
        }

        void NextLevel()
        {
            currentLevelNumber++;
            elapsedTime = 0;
            player.position = Vector2D(375, 400);
            player.velocity = Vector2D(0, 0);
        }
    };

    class LevelGenerator
    {
    public:
        static GameLevel GenerateLevel(int levelNumber)
        {
            GameLevel level;
            level.levelNumber = levelNumber;
            level.timeLimit = 120.0 + (levelNumber * 30.0);
            level.targetScore = 500 * levelNumber;

            switch (levelNumber)
            {
            case 1:
                level.name = L"The Curing Chamber";
                level.description = L"Learn the basics in the aging room";
                GenerateLevel1(level);
                break;
            case 2:
                level.name = L"The Spice Market";
                level.description = L"Navigate through aromatic obstacles";
                GenerateLevel2(level);
                break;
            case 3:
                level.name = L"The Fermentation Zone";
                level.description = L"Survive the acidic environment";
                GenerateLevel3(level);
                break;
            case 4:
                level.name = L"The Smokehouse";
                level.description = L"Dodge smoking salamis";
                GenerateLevel4(level);
                break;
            case 5:
                level.name = L"The Grand Delicatessen";
                level.description = L"Face the Master Salami Chef";
                GenerateLevel5(level);
                break;
            default:
                level.name = L"Bonus Level " + std::to_wstring(levelNumber - 5);
                level.description = L"Extreme challenge!";
                GenerateBonusLevel(level, levelNumber);
                break;
            }

            return level;
        }

    private:
        static void GenerateLevel1(GameLevel& level)
        {
            // Simple obstacles
            level.obstacles.push_back(Obstacle(150, 100, 40, 100));
            level.obstacles.push_back(Obstacle(350, 150, 50, 120));
            level.obstacles.push_back(Obstacle(550, 80, 45, 110));

            // Collectibles
            level.collectibles.push_back(Collectible(120, 350, 50, L"Cheese"));
            level.collectibles.push_back(Collectible(300, 320, 50, L"Cheese"));
            level.collectibles.push_back(Collectible(480, 380, 50, L"Cheese"));
            level.collectibles.push_back(Collectible(620, 340, 50, L"Cheese"));

            // Power-ups
            level.powerUps.push_back(PowerUp(400, 250, PowerUpType::Shield));
        }

        static void GenerateLevel2(GameLevel& level)
        {
            // More obstacles
            for (int i = 0; i < 8; i++)
            {
                level.obstacles.push_back(Obstacle(100 + i * 90, 80 + (i % 3) * 80, 35 + i * 2, 90 + i * 5));
            }

            // More collectibles
            for (int i = 0; i < 8; i++)
            {
                level.collectibles.push_back(Collectible(80 + i * 85, 300 + (i % 2) * 80, 75, L"Olives"));
            }

            // Power-ups
            level.powerUps.push_back(PowerUp(200, 250, PowerUpType::SpeedBoost));
            level.powerUps.push_back(PowerUp(600, 250, PowerUpType::DoublePoints));

            // Add enemies
            Enemy enemy1(250, 200, EnemyType::PatrolSalami);
            enemy1.patrolStart = Vector2D(150, 200);
            enemy1.patrolEnd = Vector2D(350, 200);
            level.enemies.push_back(enemy1);
        }

        static void GenerateLevel3(GameLevel& level)
        {
            // Complex obstacle patterns
            for (int i = 0; i < 10; i++)
            {
                level.obstacles.push_back(Obstacle(50 + i * 75, 50 + (i % 4) * 70, 40, 100));
            }

            // High-value collectibles
            for (int i = 0; i < 10; i++)
            {
                level.collectibles.push_back(Collectible(70 + i * 70, 320 + (i % 3) * 60, 100, L"Prosciutto"));
            }

            // Multiple power-ups
            level.powerUps.push_back(PowerUp(150, 200, PowerUpType::Shield));
            level.powerUps.push_back(PowerUp(450, 220, PowerUpType::Invincibility));
            level.powerUps.push_back(PowerUp(650, 200, PowerUpType::ExtraLife));

            // More enemies
            for (int i = 0; i < 3; i++)
            {
                Enemy enemy(200 + i * 200, 150, EnemyType::ChargingSalami);
                level.enemies.push_back(enemy);
            }
        }

        static void GenerateLevel4(GameLevel& level)
        {
            // Dense obstacles
            for (int i = 0; i < 15; i++)
            {
                level.obstacles.push_back(Obstacle(40 + i * 50, 40 + (i % 5) * 60, 35, 95));
            }

            // Many collectibles
            for (int i = 0; i < 12; i++)
            {
                level.collectibles.push_back(Collectible(60 + i * 60, 300 + (i % 4) * 50, 150, L"Chorizo"));
            }

            // Power-ups
            level.powerUps.push_back(PowerUp(100, 180, PowerUpType::SpeedBoost));
            level.powerUps.push_back(PowerUp(300, 200, PowerUpType::Shield));
            level.powerUps.push_back(PowerUp(500, 180, PowerUpType::DoublePoints));
            level.powerUps.push_back(PowerUp(700, 200, PowerUpType::Invincibility));

            // Flying and spinning enemies
            for (int i = 0; i < 4; i++)
            {
                level.enemies.push_back(Enemy(150 + i * 150, 100, EnemyType::FlyingSalami));
            }
            for (int i = 0; i < 2; i++)
            {
                level.enemies.push_back(Enemy(250 + i * 250, 250, EnemyType::SpinningSalami));
            }
        }

        static void GenerateLevel5(GameLevel& level)
        {
            // Boss level
            level.boss = new Boss(L"Master Salami Chef", 50);

            // Supporting obstacles
            for (int i = 0; i < 6; i++)
            {
                level.obstacles.push_back(Obstacle(100 + i * 100, 350, 40, 80));
            }

            // Health collectibles
            for (int i = 0; i < 5; i++)
            {
                level.collectibles.push_back(Collectible(120 + i * 120, 450, 200, L"Health Pack"));
            }

            // All power-ups available
            level.powerUps.push_back(PowerUp(100, 300, PowerUpType::Shield));
            level.powerUps.push_back(PowerUp(300, 300, PowerUpType::SpeedBoost));
            level.powerUps.push_back(PowerUp(500, 300, PowerUpType::DoublePoints));
            level.powerUps.push_back(PowerUp(700, 300, PowerUpType::Invincibility));
        }

        static void GenerateBonusLevel(GameLevel& level, int levelNumber)
        {
            int difficulty = levelNumber - 5;

            // Increase obstacle count
            for (int i = 0; i < 10 + difficulty * 5; i++)
            {
                level.obstacles.push_back(Obstacle(
                    50 + (i * 70) % 700,
                    50 + (i % 6) * 60,
                    30 + (i % 3) * 10,
                    90 + (i % 4) * 10
                ));
            }

            // More collectibles
            for (int i = 0; i < 15 + difficulty * 3; i++)
            {
                level.collectibles.push_back(Collectible(
                    60 + (i * 50) % 700,
                    300 + (i % 5) * 40,
                    100 + difficulty * 50,
                    L"Bonus Item"
                ));
            }

            // More enemies
            for (int i = 0; i < 3 + difficulty; i++)
            {
                EnemyType type = static_cast<EnemyType>(i % 4);
                level.enemies.push_back(Enemy(100 + i * 150, 150, type));
            }
        }
    };
}
