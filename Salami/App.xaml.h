#pragma once

#include "App.xaml.g.h"

namespace winrt::Salami::implementation
{
    struct App : AppT<App>
    {
        App();

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);

    private:
        winrt::Microsoft::UI::Xaml::Window window{ nullptr };
    };
}

namespace winrt::Salami::factory_implementation
{
    struct App : AppT<App, implementation::App>
    {
    };
}
