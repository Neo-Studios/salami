#include "pch.h"
#include "PresentationPage.xaml.h"
#if __has_include("PresentationPage.g.cpp")
#include "PresentationPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;

namespace winrt::Salami::implementation
{
    PresentationPage::PresentationPage()
    {
        InitializeComponent();
        InitializePresentation();
        LoadDefaultSlides();
        UpdateSlideList();
    }

    void PresentationPage::InitializePresentation()
    {
        m_metadata.filename = L"Untitled.salslides";
        m_metadata.title = L"Salami Presentation";
        m_metadata.author = L"Salami Enthusiast";
        m_metadata.company = L"Salami Appreciation Society";
        m_metadata.subject = L"The Excellence of Salami";
        m_metadata.created = std::chrono::system_clock::now();
        m_metadata.modified = std::chrono::system_clock::now();
        m_metadata.isModified = false;
        
        m_currentSlideIndex = 0;
        m_inSlideshowMode = false;
        m_showGrid = false;
        m_showRuler = true;
        m_zoomLevel = 1.0;
    }

    void PresentationPage::LoadDefaultSlides()
    {
        // Title Slide
        SlideData titleSlide;
        titleSlide.slideNumber = 1;
        titleSlide.layout = SlideLayout::Title;
        titleSlide.title = L"🥓 The Art of Salami";
        titleSlide.content = L"A Comprehensive Guide to World's Finest Cured Meat";
        titleSlide.transition = TransitionType::Fade;
        titleSlide.transitionDuration = 1.0;
        titleSlide.created = std::chrono::system_clock::now();
        titleSlide.notes = L"Welcome everyone to this presentation on salami. We'll explore varieties, history, and appreciation.";
        m_slides.push_back(titleSlide);
        
        // Salami Varieties Slide
        SlideData varietiesSlide;
        varietiesSlide.slideNumber = 2;
        varietiesSlide.layout = SlideLayout::SalamiVarieties;
        varietiesSlide.title = L"Salami Varieties Around the World";
        varietiesSlide.content = L"Italian Excellence:\n"
                                 L"• Genoa Salami - Garlicky and tangy\n"
                                 L"• Soppressata - Coarsely ground, bold\n"
                                 L"• Calabrese - Spicy with hot peppers\n\n"
                                 L"Spanish Traditions:\n"
                                 L"• Chorizo - Paprika-rich and smoky\n"
                                 L"• Salchichón - Peppercorn-studded\n\n"
                                 L"French Classics:\n"
                                 L"• Saucisson Sec - Dry and refined\n"
                                 L"• Rosette de Lyon - Delicate flavor";
        varietiesSlide.transition = TransitionType::Slide;
        varietiesSlide.created = std::chrono::system_clock::now();
        varietiesSlide.notes = L"Each region has developed unique salami styles based on local ingredients and traditions.";
        m_slides.push_back(varietiesSlide);
        
        // History Slide
        SlideData historySlide;
        historySlide.slideNumber = 3;
        historySlide.layout = SlideLayout::TitleAndContent;
        historySlide.title = L"A Rich History";
        historySlide.content = L"3000 BCE - Ancient Origins\n"
                              L"First preserved meats in Mediterranean\n\n"
                              L"800 CE - Medieval Development\n"
                              L"Italian monasteries perfect recipes\n\n"
                              L"1400s - Renaissance Expansion\n"
                              L"Trade routes spread techniques\n\n"
                              L"1800s - Industrial Revolution\n"
                              L"Commercial production begins\n\n"
                              L"2000s - Modern Era\n"
                              L"Artisanal revival, global appreciation";
        historySlide.transition = TransitionType::Zoom;
        historySlide.created = std::chrono::system_clock::now();
        historySlide.notes = L"Salami has evolved over millennia from necessity to artform.";
        m_slides.push_back(historySlide);
        
        // Pairing Guide Slide
        SlideData pairingSlide;
        pairingSlide.slideNumber = 4;
        pairingSlide.layout = SlideLayout::PairingGuide;
        pairingSlide.title = L"Perfect Pairings";
        pairingSlide.content = L"Wine Pairings:\n"
                              L"• Chianti - Italian salami\n"
                              L"• Rioja - Spanish chorizo\n"
                              L"• Côtes du Rhône - French saucisson\n\n"
                              L"Cheese Companions:\n"
                              L"• Parmigiano-Reggiano - Sharp contrast\n"
                              L"• Manchego - Spanish harmony\n"
                              L"• Aged Gouda - Nutty complement\n\n"
                              L"Bread Selections:\n"
                              L"• Ciabatta - Rustic Italian\n"
                              L"• Baguette - French classic\n"
                              L"• Sourdough - Tangy base";
        pairingSlide.transition = TransitionType::Fade;
        pairingSlide.created = std::chrono::system_clock::now();
        pairingSlide.notes = L"Proper pairing elevates the salami tasting experience.";
        m_slides.push_back(pairingSlide);
        
        // Recipe Slide
        SlideData recipeSlide;
        recipeSlide.slideNumber = 5;
        recipeSlide.layout = SlideLayout::Recipe;
        recipeSlide.title = L"Featured Recipe: Ultimate Salami Platter";
        recipeSlide.content = L"Ingredients:\n"
                             L"• 3-4 varieties of salami (200g each)\n"
                             L"• Assorted cheeses (400g total)\n"
                             L"• Olives, cornichons, peppers\n"
                             L"• Crackers and fresh bread\n"
                             L"• Honey, fig jam, mustard\n\n"
                             L"Assembly:\n"
                             L"1. Arrange meats in rosettes\n"
                             L"2. Place cheeses at angles\n"
                             L"3. Fill gaps with accompaniments\n"
                             L"4. Add small bowls of spreads\n"
                             L"5. Garnish with fresh herbs\n\n"
                             L"Serve at room temperature for best flavor!";
        recipeSlide.transition = TransitionType::Slide;
        recipeSlide.created = std::chrono::system_clock::now();
        recipeSlide.notes = L"Allow salami to come to room temperature 30 minutes before serving.";
        m_slides.push_back(recipeSlide);
        
        // Conclusion Slide
        SlideData conclusionSlide;
        conclusionSlide.slideNumber = 6;
        conclusionSlide.layout = SlideLayout::TitleAndContent;
        conclusionSlide.title = L"The Salami Experience";
        conclusionSlide.content = L"Key Takeaways:\n\n"
                                 L"✓ Salami is a centuries-old culinary tradition\n\n"
                                 L"✓ Every region has unique varieties\n\n"
                                 L"✓ Proper pairing enhances flavor\n\n"
                                 L"✓ Quality ingredients make the difference\n\n"
                                 L"✓ Salami brings people together\n\n"
                                 L"Thank you for joining this journey through the world of salami!";
        conclusionSlide.transition = TransitionType::Fade;
        conclusionSlide.created = std::chrono::system_clock::now();
        conclusionSlide.notes = L"End with enthusiasm. Invite questions about salami varieties or preparation.";
        m_slides.push_back(conclusionSlide);
    }

    // File Menu Implementations
    void PresentationPage::New_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_metadata.isModified)
        {
            // Show save prompt
        }
        
        m_slides.clear();
        LoadDefaultSlides();
        m_currentSlideIndex = 0;
        InitializePresentation();
        UpdateSlideList();
    }

    void PresentationPage::Open_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Show file picker and load presentation
    }

    void PresentationPage::Save_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_metadata.filename == L"Untitled.salslides")
        {
            SaveAs_Click(nullptr, nullptr);
        }
        else
        {
            SavePresentation();
        }
    }

    void PresentationPage::SaveAs_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Show save dialog
    }

    void PresentationPage::ExportPDF_Click(IInspectable const&, RoutedEventArgs const&)
    {
        ExportToPDF();
    }

    void PresentationPage::ExportVideo_Click(IInspectable const&, RoutedEventArgs const&)
    {
        ExportToVideo();
    }

    void PresentationPage::Print_Click(IInspectable const&, RoutedEventArgs const&)
    {
        PrintSlides();
    }

    void PresentationPage::PrintHandouts_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Print handouts format
    }

    void PresentationPage::PrintNotes_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Print notes pages
    }

    void PresentationPage::Close_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_metadata.isModified)
        {
            // Show save prompt
        }
    }

    // Edit Menu Implementations
    void PresentationPage::Undo_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Implement undo
    }

    void PresentationPage::Redo_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Implement redo
    }

    void PresentationPage::Cut_Click(IInspectable const&, RoutedEventArgs const&)
    {
        Copy_Click(nullptr, nullptr);
        Delete_Click(nullptr, nullptr);
    }

    void PresentationPage::Copy_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Copy current slide
    }

    void PresentationPage::Paste_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Paste slide
    }

    void PresentationPage::Delete_Click(IInspectable const&, RoutedEventArgs const&)
    {
        DeleteSlide_Click(nullptr, nullptr);
    }

    void PresentationPage::Duplicate_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_currentSlideIndex >= 0 && m_currentSlideIndex < m_slides.size())
        {
            auto duplicatedSlide = m_slides[m_currentSlideIndex];
            duplicatedSlide.slideNumber = static_cast<int>(m_slides.size()) + 1;
            m_slides.insert(m_slides.begin() + m_currentSlideIndex + 1, duplicatedSlide);
            m_metadata.isModified = true;
            UpdateSlideList();
        }
    }

    // Insert Menu Implementations
    void PresentationPage::NewSlide_Click(IInspectable const&, RoutedEventArgs const&)
    {
        AddSlide_Click(nullptr, nullptr);
    }

    void PresentationPage::InsertText_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Insert text box
    }

    void PresentationPage::InsertImage_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Insert image
    }

    void PresentationPage::InsertShape_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Insert shape
    }

    void PresentationPage::InsertTable_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Insert table
    }

    void PresentationPage::InsertChart_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Insert chart
    }

    void PresentationPage::InsertVideo_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Insert video
    }

    void PresentationPage::InsertAudio_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Insert audio
    }

    // Design Menu Implementations
    void PresentationPage::DesignTheme_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Show theme selector
    }

    void PresentationPage::SalamiTheme_Click(IInspectable const&, RoutedEventArgs const&)
    {
        LoadSalamiTheme();
    }

    void PresentationPage::BackgroundFormat_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Show background formatting dialog
    }

    void PresentationPage::SlideSize_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Show slide size options
    }

    // Transitions Menu Implementations
    void PresentationPage::TransitionNone_Click(IInspectable const&, RoutedEventArgs const&)
    {
        ApplyTransition(TransitionType::None, m_currentSlideIndex);
    }

    void PresentationPage::TransitionFade_Click(IInspectable const&, RoutedEventArgs const&)
    {
        ApplyTransition(TransitionType::Fade, m_currentSlideIndex);
    }

    void PresentationPage::TransitionSlide_Click(IInspectable const&, RoutedEventArgs const&)
    {
        ApplyTransition(TransitionType::Slide, m_currentSlideIndex);
    }

    void PresentationPage::TransitionZoom_Click(IInspectable const&, RoutedEventArgs const&)
    {
        ApplyTransition(TransitionType::Zoom, m_currentSlideIndex);
    }

    void PresentationPage::TransitionFlip_Click(IInspectable const&, RoutedEventArgs const&)
    {
        ApplyTransition(TransitionType::Flip, m_currentSlideIndex);
    }

    void PresentationPage::TransitionDuration_Changed(IInspectable const&, Microsoft::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs const& args)
    {
        if (m_currentSlideIndex >= 0 && m_currentSlideIndex < m_slides.size())
        {
            m_slides[m_currentSlideIndex].transitionDuration = args.NewValue();
            m_metadata.isModified = true;
        }
    }

    // Animations Menu Implementations
    void PresentationPage::AddAnimation_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Show animation wizard
    }

    void PresentationPage::AnimationPane_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Toggle animation pane
    }

    // Slideshow Menu Implementations
    void PresentationPage::StartFromBeginning_Click(IInspectable const&, RoutedEventArgs const&)
    {
        PlaySlideshow(0);
    }

    void PresentationPage::StartFromCurrent_Click(IInspectable const&, RoutedEventArgs const&)
    {
        PlaySlideshow(m_currentSlideIndex);
    }

    void PresentationPage::PresenterView_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Open presenter view
    }

    void PresentationPage::SetupShow_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Show slideshow setup dialog
    }

    void PresentationPage::Rehearse_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Start rehearsal mode with timer
    }

    // View Menu Implementations
    void PresentationPage::NormalView_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Switch to normal view
    }

    void PresentationPage::SlideSorter_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Switch to slide sorter view
    }

    void PresentationPage::NotesPage_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Switch to notes page view
    }

    void PresentationPage::GridLines_Click(IInspectable const&, RoutedEventArgs const&)
    {
        m_showGrid = !m_showGrid;
        // Toggle grid lines on canvas
    }

    void PresentationPage::Ruler_Click(IInspectable const&, RoutedEventArgs const&)
    {
        m_showRuler = !m_showRuler;
        // Toggle ruler display
    }

    // Slide Management
    void PresentationPage::SlideList_SelectionChanged(IInspectable const&, SelectionChangedEventArgs const& args)
    {
        // Update current slide index
        if (args.AddedItems().Size() > 0)
        {
            // Get selected slide index
            m_currentSlideIndex = 0; // Update with actual index
            RenderSlide(m_slides[m_currentSlideIndex]);
            UpdatePropertiesPanel();
        }
    }

    void PresentationPage::AddSlide_Click(IInspectable const&, RoutedEventArgs const&)
    {
        SlideData newSlide;
        newSlide.slideNumber = static_cast<int>(m_slides.size()) + 1;
        newSlide.layout = SlideLayout::TitleAndContent;
        newSlide.title = L"New Slide";
        newSlide.content = L"Click to add content";
        newSlide.transition = TransitionType::None;
        newSlide.created = std::chrono::system_clock::now();
        
        m_slides.push_back(newSlide);
        m_currentSlideIndex = static_cast<int>(m_slides.size()) - 1;
        m_metadata.isModified = true;
        UpdateSlideList();
    }

    void PresentationPage::DeleteSlide_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_slides.size() > 1 && m_currentSlideIndex >= 0 && m_currentSlideIndex < m_slides.size())
        {
            m_slides.erase(m_slides.begin() + m_currentSlideIndex);
            m_currentSlideIndex = std::max(0, m_currentSlideIndex - 1);
            
            // Renumber slides
            for (size_t i = 0; i < m_slides.size(); i++)
            {
                m_slides[i].slideNumber = static_cast<int>(i) + 1;
            }
            
            m_metadata.isModified = true;
            UpdateSlideList();
        }
    }

    void PresentationPage::MoveSlideUp_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_currentSlideIndex > 0)
        {
            std::swap(m_slides[m_currentSlideIndex], m_slides[m_currentSlideIndex - 1]);
            m_slides[m_currentSlideIndex].slideNumber = m_currentSlideIndex + 1;
            m_slides[m_currentSlideIndex - 1].slideNumber = m_currentSlideIndex;
            m_currentSlideIndex--;
            m_metadata.isModified = true;
            UpdateSlideList();
        }
    }

    void PresentationPage::MoveSlideDown_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_currentSlideIndex < m_slides.size() - 1)
        {
            std::swap(m_slides[m_currentSlideIndex], m_slides[m_currentSlideIndex + 1]);
            m_slides[m_currentSlideIndex].slideNumber = m_currentSlideIndex + 1;
            m_slides[m_currentSlideIndex + 1].slideNumber = m_currentSlideIndex + 2;
            m_currentSlideIndex++;
            m_metadata.isModified = true;
            UpdateSlideList();
        }
    }

    // Template Applications
    void PresentationPage::TemplateBlank_Click(IInspectable const&, RoutedEventArgs const&)
    {
        ApplyTemplate(SlideLayout::Blank, m_currentSlideIndex);
    }

    void PresentationPage::TemplateTitle_Click(IInspectable const&, RoutedEventArgs const&)
    {
        ApplyTemplate(SlideLayout::Title, m_currentSlideIndex);
    }

    void PresentationPage::TemplateTitleContent_Click(IInspectable const&, RoutedEventArgs const&)
    {
        ApplyTemplate(SlideLayout::TitleAndContent, m_currentSlideIndex);
    }

    void PresentationPage::TemplateTwoContent_Click(IInspectable const&, RoutedEventArgs const&)
    {
        ApplyTemplate(SlideLayout::TwoContent, m_currentSlideIndex);
    }

    void PresentationPage::TemplateComparison_Click(IInspectable const&, RoutedEventArgs const&)
    {
        ApplyTemplate(SlideLayout::Comparison, m_currentSlideIndex);
    }

    void PresentationPage::TemplateSalamiVarieties_Click(IInspectable const&, RoutedEventArgs const&)
    {
        AddSalamiVarietiesSlide();
    }

    void PresentationPage::TemplatePairingGuide_Click(IInspectable const&, RoutedEventArgs const&)
    {
        AddPairingGuideSlide();
    }

    void PresentationPage::TemplateRecipe_Click(IInspectable const&, RoutedEventArgs const&)
    {
        AddRecipeSlide();
    }

    void PresentationPage::TemplateComparison_SalamiClick(IInspectable const&, RoutedEventArgs const&)
    {
        // Add salami comparison slide
    }

    // Private Helper Methods
    void PresentationPage::CreateSlide(SlideLayout layout)
    {
        SlideData slide;
        slide.slideNumber = static_cast<int>(m_slides.size()) + 1;
        slide.layout = layout;
        slide.transition = TransitionType::None;
        slide.created = std::chrono::system_clock::now();
        
        switch (layout)
        {
        case SlideLayout::Blank:
            slide.title = L"";
            slide.content = L"";
            break;
        case SlideLayout::Title:
            slide.title = L"Title Slide";
            slide.content = L"Subtitle";
            break;
        case SlideLayout::TitleAndContent:
            slide.title = L"Slide Title";
            slide.content = L"• Point 1\n• Point 2\n• Point 3";
            break;
        case SlideLayout::TwoContent:
            slide.title = L"Two Content Slide";
            slide.content = L"Left Column | Right Column";
            break;
        case SlideLayout::Comparison:
            slide.title = L"Comparison";
            slide.content = L"Option A vs Option B";
            break;
        default:
            break;
        }
        
        m_slides.push_back(slide);
    }

    void PresentationPage::RenderSlide(SlideData const& slide)
    {
        // Render slide on canvas
        // Update title and content text blocks
        // Apply background and styling
        // Position elements according to layout
    }

    void PresentationPage::UpdateSlideList()
    {
        // Update slide thumbnail list
        // Highlight current slide
    }

    void PresentationPage::UpdatePropertiesPanel()
    {
        // Update properties panel with current slide settings
        // Transition type, duration, notes
    }

    void PresentationPage::ApplyTemplate(SlideLayout layout, int slideIndex)
    {
        if (slideIndex >= 0 && slideIndex < m_slides.size())
        {
            m_slides[slideIndex].layout = layout;
            RenderSlide(m_slides[slideIndex]);
            m_metadata.isModified = true;
        }
    }

    void PresentationPage::ApplyTransition(TransitionType transition, int slideIndex)
    {
        if (slideIndex >= 0 && slideIndex < m_slides.size())
        {
            m_slides[slideIndex].transition = transition;
            m_metadata.isModified = true;
            UpdatePropertiesPanel();
        }
    }

    void PresentationPage::PlaySlideshow(int startSlide)
    {
        m_inSlideshowMode = true;
        m_currentSlideIndex = startSlide;
        // Enter fullscreen mode
        // Start slideshow presentation
    }

    void PresentationPage::NextSlide()
    {
        if (m_currentSlideIndex < m_slides.size() - 1)
        {
            m_currentSlideIndex++;
            RenderSlide(m_slides[m_currentSlideIndex]);
        }
        else
        {
            ExitSlideshow();
        }
    }

    void PresentationPage::PreviousSlide()
    {
        if (m_currentSlideIndex > 0)
        {
            m_currentSlideIndex--;
            RenderSlide(m_slides[m_currentSlideIndex]);
        }
    }

    void PresentationPage::ExitSlideshow()
    {
        m_inSlideshowMode = false;
        // Exit fullscreen mode
        // Return to normal view
    }

    void PresentationPage::SavePresentation()
    {
        // Serialize presentation data
        m_metadata.modified = std::chrono::system_clock::now();
        m_metadata.isModified = false;
    }

    void PresentationPage::LoadPresentation(std::wstring const& filepath)
    {
        // Deserialize presentation data
    }

    void PresentationPage::ExportToPDF()
    {
        // Export all slides to PDF
        // One slide per page
    }

    void PresentationPage::ExportToVideo()
    {
        // Export presentation as video
        // Apply transitions and animations
    }

    void PresentationPage::PrintSlides()
    {
        // Print slides to printer
    }

    void PresentationPage::AddSalamiVarietiesSlide()
    {
        SlideData slide;
        slide.slideNumber = static_cast<int>(m_slides.size()) + 1;
        slide.layout = SlideLayout::SalamiVarieties;
        slide.title = L"Exploring Salami Varieties";
        slide.content = L"Italian Classics:\n"
                       L"• Genoa - Garlicky, wine-cured\n"
                       L"• Milano - Mild, finely ground\n"
                       L"• Soppressata - Coarse, rustic\n\n"
                       L"Spanish Delights:\n"
                       L"• Chorizo - Paprika, smoky\n"
                       L"• Salchichón - Peppercorn-rich\n\n"
                       L"European Excellence:\n"
                       L"• Saucisson Sec (France)\n"
                       L"• Teewurst (Germany)";
        slide.transition = TransitionType::Slide;
        slide.notes = L"Discuss regional differences in spicing and curing methods.";
        slide.created = std::chrono::system_clock::now();
        
        m_slides.push_back(slide);
        m_currentSlideIndex = static_cast<int>(m_slides.size()) - 1;
        m_metadata.isModified = true;
        UpdateSlideList();
    }

    void PresentationPage::AddPairingGuideSlide()
    {
        SlideData slide;
        slide.slideNumber = static_cast<int>(m_slides.size()) + 1;
        slide.layout = SlideLayout::PairingGuide;
        slide.title = L"The Art of Pairing Salami";
        slide.content = L"Wine Matches:\n"
                       L"• Red: Chianti, Rioja, Zinfandel\n"
                       L"• White: Pinot Grigio, Albariño\n\n"
                       L"Cheese Partners:\n"
                       L"• Aged: Parmigiano, Manchego\n"
                       L"• Soft: Brie, Fresh Mozzarella\n\n"
                       L"Accompaniments:\n"
                       L"• Olives, cornichons, peppers\n"
                       L"• Fig jam, honey, mustard\n"
                       L"• Fresh bread, crackers";
        slide.transition = TransitionType::Fade;
        slide.notes = L"Emphasize complementary and contrasting flavors.";
        slide.created = std::chrono::system_clock::now();
        
        m_slides.push_back(slide);
        m_currentSlideIndex = static_cast<int>(m_slides.size()) - 1;
        m_metadata.isModified = true;
        UpdateSlideList();
    }

    void PresentationPage::AddRecipeSlide()
    {
        SlideData slide;
        slide.slideNumber = static_cast<int>(m_slides.size()) + 1;
        slide.layout = SlideLayout::Recipe;
        slide.title = L"Signature Salami Dish";
        slide.content = L"Salami & Arugula Pizza\n\n"
                       L"Ingredients:\n"
                       L"• Pizza dough (homemade or store-bought)\n"
                       L"• Tomato sauce, 1 cup\n"
                       L"• Mozzarella cheese, 8 oz\n"
                       L"• Genoa salami, thinly sliced\n"
                       L"• Fresh arugula, 2 cups\n"
                       L"• Parmesan shavings\n"
                       L"• Olive oil, balsamic glaze\n\n"
                       L"Instructions:\n"
                       L"1. Preheat oven to 450°F (230°C)\n"
                       L"2. Roll dough, spread sauce, add cheese\n"
                       L"3. Top with salami slices\n"
                       L"4. Bake 12-15 minutes until crispy\n"
                       L"5. Top with arugula and parmesan\n"
                       L"6. Drizzle with oil and balsamic";
        slide.transition = TransitionType::Zoom;
        slide.notes = L"Great recipe for showcasing quality salami.";
        slide.created = std::chrono::system_clock::now();
        
        m_slides.push_back(slide);
        m_currentSlideIndex = static_cast<int>(m_slides.size()) - 1;
        m_metadata.isModified = true;
        UpdateSlideList();
    }

    void PresentationPage::LoadSalamiTheme()
    {
        // Apply salami-themed colors and styling to all slides
        for (auto& slide : m_slides)
        {
            // Set background colors from salami palette
            // SalamiRed, SalamiPink, SalamiWhite, SalamiBrown
        }
        
        m_metadata.isModified = true;
        RenderSlide(m_slides[m_currentSlideIndex]);
    }
}
