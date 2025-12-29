#pragma once

#include "PairingPage.g.h"

namespace winrt::Salami::implementation
{
    struct PairingPage : PairingPageT<PairingPage>
    {
        PairingPage() = default;
    };
}

namespace winrt::Salami::factory_implementation
{
    struct PairingPage : PairingPageT<PairingPage, implementation::PairingPage>
    {
    };
}
