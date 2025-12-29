#pragma once
#include "pch.h"
#include "Models.h"
#include <vector>
#include <memory>

namespace Salami::Data
{
    class SalamiDatabase
    {
    public:
        // Get all salami varieties
        static std::vector<Models::SalamiVariety> GetAllSalamiVarieties();
        
        // Get varieties by region
        static std::vector<Models::SalamiVariety> GetVarietiesByRegion(Models::Region region);
        
        // Get varieties by spice level
        static std::vector<Models::SalamiVariety> GetVarietiesBySpiceLevel(Models::SpiceLevel level);
        
        // Get all recipes
        static std::vector<Models::Recipe> GetAllRecipes();
        
        // Get recipes by category
        static std::vector<Models::Recipe> GetRecipesByCategory(const std::wstring& category);
        
        // Get historical events
        static std::vector<Models::HistoricalEvent> GetHistoricalTimeline();
        
        // Get pairing recommendations
        static std::vector<Models::PairingRecommendation> GetPairingRecommendations();
        
        // Get production steps
        static std::vector<Models::ProductionStep> GetProductionSteps();
        
        // Get fun facts
        static std::vector<Models::FunFact> GetFunFacts();
        
        // Get festivals
        static std::vector<Models::SalamiFestival> GetFestivals();
        
    private:
        static std::vector<Models::SalamiVariety> CreateItalianSalamis();
        static std::vector<Models::SalamiVariety> CreateSpanishSalamis();
        static std::vector<Models::SalamiVariety> CreateFrenchSalamis();
        static std::vector<Models::SalamiVariety> CreateGermanSalamis();
        static std::vector<Models::SalamiVariety> CreateOtherSalamis();
        
        static std::vector<Models::Recipe> CreateAppetizerRecipes();
        static std::vector<Models::Recipe> CreateMainCourseRecipes();
        static std::vector<Models::Recipe> CreateSnackRecipes();
        
        static std::vector<Models::HistoricalEvent> CreateAncientHistory();
        static std::vector<Models::HistoricalEvent> CreateMedievalHistory();
        static std::vector<Models::HistoricalEvent> CreateModernHistory();
    };
}
