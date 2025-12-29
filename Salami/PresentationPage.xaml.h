#pragma once
#include "PresentationPage.g.h"
#include <vector>
#include <string>
#include <chrono>

namespace winrt::Salami::implementation
{
    struct PresentationPage : PresentationPageT<PresentationPage>
    {
        PresentationPage();

        // File Menu
        void New_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Open_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Save_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void SaveAs_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void ExportPDF_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void ExportVideo_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Print_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void PrintHandouts_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void PrintNotes_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Close_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

        // Edit Menu
        void Undo_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Redo_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Cut_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Copy_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Paste_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Delete_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Duplicate_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

        // Insert Menu
        void NewSlide_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void InsertText_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void InsertImage_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void InsertShape_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void InsertTable_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void InsertChart_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void InsertVideo_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void InsertAudio_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

        // Design Menu
        void DesignTheme_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void SalamiTheme_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void BackgroundFormat_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void SlideSize_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

        // Transitions Menu
        void TransitionNone_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void TransitionFade_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void TransitionSlide_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void TransitionZoom_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void TransitionFlip_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void TransitionDuration_Changed(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs const& args);

        // Animations Menu
        void AddAnimation_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void AnimationPane_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

        // Slideshow Menu
        void StartFromBeginning_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void StartFromCurrent_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void PresenterView_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void SetupShow_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Rehearse_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

        // View Menu
        void NormalView_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void SlideSorter_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void NotesPage_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void GridLines_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Ruler_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

        // Slide Management
        void SlideList_SelectionChanged(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs const& args);
        void AddSlide_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void DeleteSlide_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void MoveSlideUp_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void MoveSlideDown_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

        // Templates
        void TemplateBlank_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void TemplateTitle_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void TemplateTitleContent_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void TemplateTwoContent_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void TemplateComparison_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void TemplateSalamiVarieties_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void TemplatePairingGuide_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void TemplateRecipe_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void TemplateComparison_SalamiClick(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

    private:
        enum class SlideLayout
        {
            Blank,
            Title,
            TitleAndContent,
            TwoContent,
            Comparison,
            SalamiVarieties,
            PairingGuide,
            Recipe
        };

        enum class TransitionType
        {
            None,
            Fade,
            Slide,
            Zoom,
            Flip
        };

        enum class AnimationType
        {
            None,
            Appear,
            FadeIn,
            FlyIn,
            Zoom,
            Spin
        };

        struct SlideElement
        {
            std::wstring type; // text, image, shape, table, chart
            std::wstring content;
            double x, y, width, height;
            std::wstring fontFamily;
            double fontSize;
            Microsoft::UI::Xaml::Media::Brush foreground{ nullptr };
            Microsoft::UI::Xaml::Media::Brush background{ nullptr };
            AnimationType animation{ AnimationType::None };
            double animationDelay{ 0.0 };
        };

        struct SlideData
        {
            int slideNumber;
            SlideLayout layout;
            std::wstring title;
            std::wstring content;
            std::vector<SlideElement> elements;
            Microsoft::UI::Xaml::Media::Brush background{ nullptr };
            TransitionType transition{ TransitionType::None };
            double transitionDuration{ 1.0 };
            std::wstring notes;
            std::chrono::system_clock::time_point created;
        };

        struct PresentationMetadata
        {
            std::wstring filename{ L"Untitled.salslides" };
            std::wstring title{ L"Salami Presentation" };
            std::wstring author;
            std::wstring company;
            std::wstring subject;
            std::chrono::system_clock::time_point created;
            std::chrono::system_clock::time_point modified;
            bool isModified{ false };
        };

        // Private methods
        void InitializePresentation();
        void LoadDefaultSlides();
        void CreateSlide(SlideLayout layout);
        void RenderSlide(SlideData const& slide);
        void UpdateSlideList();
        void UpdatePropertiesPanel();
        void ApplyTemplate(SlideLayout layout, int slideIndex);
        void ApplyTransition(TransitionType transition, int slideIndex);
        void PlaySlideshow(int startSlide);
        void NextSlide();
        void PreviousSlide();
        void ExitSlideshow();
        void SavePresentation();
        void LoadPresentation(std::wstring const& filepath);
        void ExportToPDF();
        void ExportToVideo();
        void PrintSlides();
        void AddSalamiVarietiesSlide();
        void AddPairingGuideSlide();
        void AddRecipeSlide();
        void LoadSalamiTheme();

        // Member variables
        std::vector<SlideData> m_slides;
        int m_currentSlideIndex{ 0 };
        PresentationMetadata m_metadata;
        bool m_inSlideshowMode{ false };
        bool m_showGrid{ false };
        bool m_showRuler{ true };
        double m_zoomLevel{ 1.0 };
    };
}

namespace winrt::Salami::factory_implementation
{
    struct PresentationPage : PresentationPageT<PresentationPage, implementation::PresentationPage>
    {
    };
}
