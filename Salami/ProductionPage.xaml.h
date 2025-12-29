#pragma once

#include "ProductionPage.g.h"

namespace winrt::Salami::implementation
{
    struct ProductionPage : ProductionPageT<ProductionPage>
    {
        ProductionPage() = default;
    };
}

namespace winrt::Salami::factory_implementation
{
    struct ProductionPage : ProductionPageT<ProductionPage, implementation::ProductionPage>
    {
    };
}
