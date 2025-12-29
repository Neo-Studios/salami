#pragma once

#include "FunFactsPage.g.h"

namespace winrt::Salami::implementation
{
    struct FunFactsPage : FunFactsPageT<FunFactsPage>
    {
        FunFactsPage() = default;
    };
}

namespace winrt::Salami::factory_implementation
{
    struct FunFactsPage : FunFactsPageT<FunFactsPage, implementation::FunFactsPage>
    {
    };
}
