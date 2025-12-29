#pragma once

#include "GalleryPage.g.h"

namespace winrt::Salami::implementation
{
    struct GalleryPage : GalleryPageT<GalleryPage>
    {
        GalleryPage() = default;
    };
}

namespace winrt::Salami::factory_implementation
{
    struct GalleryPage : GalleryPageT<GalleryPage, implementation::GalleryPage>
    {
    };
}
