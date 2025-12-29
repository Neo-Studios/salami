#pragma once

#include "RecipesPage.g.h"

namespace winrt::Salami::implementation
{
    struct RecipesPage : RecipesPageT<RecipesPage>
    {
        RecipesPage() = default;
    };
}

namespace winrt::Salami::factory_implementation
{
    struct RecipesPage : RecipesPageT<RecipesPage, implementation::RecipesPage>
    {
    };
}
