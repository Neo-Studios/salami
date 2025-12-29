#pragma once

#include "HistoryPage.g.h"

namespace winrt::Salami::implementation
{
    struct HistoryPage : HistoryPageT<HistoryPage>
    {
        HistoryPage() = default;
    };
}

namespace winrt::Salami::factory_implementation
{
    struct HistoryPage : HistoryPageT<HistoryPage, implementation::HistoryPage>
    {
    };
}
