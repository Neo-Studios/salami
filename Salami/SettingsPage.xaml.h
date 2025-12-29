#pragma once

#include "SettingsPage.g.h"

namespace winrt::Salami::implementation
{
    struct SettingsPage : SettingsPageT<SettingsPage>
    {
        SettingsPage() = default;
    };
}

namespace winrt::Salami::factory_implementation
{
    struct SettingsPage : SettingsPageT<SettingsPage, implementation::SettingsPage>
    {
    };
}
