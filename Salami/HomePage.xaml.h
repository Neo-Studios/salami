#pragma once

#include "HomePage.g.h"

namespace winrt::Salami::implementation
{
    struct HomePage : HomePageT<HomePage>
    {
        HomePage() = default;
    };
}

namespace winrt::Salami::factory_implementation
{
    struct HomePage : HomePageT<HomePage, implementation::HomePage>
    {
    };
}
