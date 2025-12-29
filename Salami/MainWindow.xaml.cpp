#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include "HomePage.xaml.h"
#include "GalleryPage.xaml.h"
#include "HistoryPage.xaml.h"
#include "RecipesPage.xaml.h"
#include "SettingsPage.xaml.h"
#include "ProductionPage.xaml.h"
#include "GamePage.xaml.h"
#include "PairingPage.xaml.h"
#include "FunFactsPage.xaml.h"
#include "CalendarPage.xaml.h"
#include "NotesPage.xaml.h"
#include "WordProcessorPage.xaml.h"
#include "SpreadsheetPage.xaml.h"
#include "PresentationPage.xaml.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;

namespace winrt::Salami::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
        Title(L"Salami - A Celebration of Excellence");
        
        // Navigate to home page by default
        ContentFrame().Navigate(xaml_typename<Salami::HomePage>());
    }

    void MainWindow::NavView_SelectionChanged(
        NavigationView const& sender,
        NavigationViewSelectionChangedEventArgs const& args)
    {
        if (args.IsSettingsSelected())
        {
            ContentFrame().Navigate(xaml_typename<Salami::SettingsPage>());
        }
        else if (args.SelectedItem())
        {
            auto selectedItem = args.SelectedItem().as<NavigationViewItem>();
            auto tag = unbox_value<hstring>(selectedItem.Tag());
            NavigateToPage(tag);
        }
    }

    void MainWindow::NavView_ItemInvoked(
        NavigationView const&,
        NavigationViewItemInvokedEventArgs const& args)
    {
        if (args.IsSettingsInvoked())
        {
            ContentFrame().Navigate(xaml_typename<Salami::SettingsPage>());
        }
    }

    void MainWindow::NavigateToPage(hstring const& pageTag)
    {
        if (pageTag == L"Home")
        {
            ContentFrame().Navigate(xaml_typename<Salami::HomePage>());
        }
        else if (pageTag == L"Gallery")
        {
            ContentFrame().Navigate(xaml_typename<Salami::GalleryPage>());
        }
        else if (pageTag == L"History")
        {
            ContentFrame().Navigate(xaml_typename<Salami::HistoryPage>());
        }
        else if (pageTag == L"Recipes")
        {
            ContentFrame().Navigate(xaml_typename<Salami::RecipesPage>());
        }
        else if (pageTag == L"Production")
        {
            ContentFrame().Navigate(xaml_typename<Salami::ProductionPage>());
        }
        else if (pageTag == L"Pairing")
        {
            ContentFrame().Navigate(xaml_typename<Salami::PairingPage>());
        }
        else if (pageTag == L"FunFacts")
        {
            ContentFrame().Navigate(xaml_typename<Salami::FunFactsPage>());
        }
        else if (pageTag == L"Game")
        {
            ContentFrame().Navigate(xaml_typename<Salami::GamePage>());
        }
        else if (pageTag == L"Calendar")
        {
            ContentFrame().Navigate(xaml_typename<Salami::CalendarPage>());
        }
        else if (pageTag == L"Notes")
        {
            ContentFrame().Navigate(xaml_typename<Salami::NotesPage>());
        }
        else if (pageTag == L"WordProcessor")
        {
            ContentFrame().Navigate(xaml_typename<Salami::WordProcessorPage>());
        }
        else if (pageTag == L"Spreadsheet")
        {
            ContentFrame().Navigate(xaml_typename<Salami::SpreadsheetPage>());
        }
        else if (pageTag == L"Presentation")
        {
            ContentFrame().Navigate(xaml_typename<Salami::PresentationPage>());
        }
    }
}
