#pragma once

#include "CalendarPage.g.h"
#include <vector>
#include <string>

namespace winrt::Salami::implementation
{
    struct CalendarEvent
    {
        std::wstring title;
        std::wstring type;
        int year;
        int month;
        int day;
        int hour;
        int minute;
    };

    struct CalendarPage : CalendarPageT<CalendarPage>
    {
        CalendarPage();

        void PrevMonth_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void NextMonth_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void Today_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void AddEvent_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);

    private:
        int m_currentYear;
        int m_currentMonth;
        std::vector<CalendarEvent> m_events;

        void UpdateCalendar();
        void PopulateCalendarGrid();
        void UpdateUpcomingEvents();
        void LoadDefaultEvents();
    };
}

namespace winrt::Salami::factory_implementation
{
    struct CalendarPage : CalendarPageT<CalendarPage, implementation::CalendarPage>
    {
    };
}
