#pragma once
#include "pch.h"
#include <string>
#include <vector>

namespace Salami::Models
{
    // Enum for salami origin regions
    enum class Region
    {
        Italy,
        Spain,
        France,
        Germany,
        Hungary,
        Poland,
        Other
    };

    // Enum for spice level
    enum class SpiceLevel
    {
        Mild,
        Medium,
        Hot,
        VeryHot
    };

    // Enum for texture
    enum class Texture
    {
        Fine,
        Medium,
        Coarse,
        Spreadable
    };

    // Enum for curing time
    enum class CuringTime
    {
        Short,      // 1-3 weeks
        Medium,     // 1-2 months
        Long,       // 3-6 months
        VeryLong    // 6+ months
    };

    // Structure representing a salami variety
    struct SalamiVariety
    {
        std::wstring name;
        std::wstring description;
        Region region;
        std::wstring regionName;
        SpiceLevel spiceLevel;
        Texture texture;
        CuringTime curingTime;
        std::vector<std::wstring> mainIngredients;
        std::vector<std::wstring> spices;
        std::wstring flavorProfile;
        std::wstring bestPairing;
        bool isProtectedDesignation;
        std::wstring funFact;
        int popularityRating; // 1-10
    };

    // Structure for recipe
    struct Recipe
    {
        std::wstring name;
        std::wstring description;
        std::wstring category; // Appetizer, Main Course, Snack, etc.
        int servings;
        int prepTimeMinutes;
        int cookTimeMinutes;
        std::wstring difficulty; // Easy, Medium, Hard
        std::vector<std::wstring> ingredients;
        std::vector<std::wstring> instructions;
        std::vector<std::wstring> tips;
        std::wstring salamiType;
        std::vector<std::wstring> pairingWines;
    };

    // Structure for historical event
    struct HistoricalEvent
    {
        std::wstring period;
        std::wstring year;
        std::wstring title;
        std::wstring description;
        std::wstring significance;
        std::wstring region;
    };

    // Structure for pairing recommendation
    struct PairingRecommendation
    {
        std::wstring salamiType;
        std::vector<std::wstring> cheeses;
        std::vector<std::wstring> wines;
        std::vector<std::wstring> beers;
        std::vector<std::wstring> breads;
        std::vector<std::wstring> accompaniments;
        std::wstring occasion;
    };

    // Structure for production step
    struct ProductionStep
    {
        int stepNumber;
        std::wstring title;
        std::wstring description;
        std::wstring duration;
        std::wstring temperature;
        std::wstring humidity;
        std::vector<std::wstring> keyPoints;
    };

    // Fun fact structure
    struct FunFact
    {
        std::wstring category;
        std::wstring fact;
        std::wstring details;
        bool isVerified;
    };

    // Salami festival structure
    struct SalamiFestival
    {
        std::wstring name;
        std::wstring location;
        std::wstring country;
        std::wstring month;
        std::wstring description;
        std::vector<std::wstring> activities;
        int estimatedAttendees;
    };
}
