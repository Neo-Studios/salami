#include "pch.h"
#include "CalendarPage.xaml.h"
#if __has_include("CalendarPage.g.cpp")
#include "CalendarPage.g.cpp"
#endif
#include <chrono>
#include <ctime>

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;

namespace winrt::Salami::implementation
{
    CalendarPage::CalendarPage()
    {
        InitializeComponent();
        
        // Get current date
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);
        std::tm tm;
        localtime_s(&tm, &time);
        
        m_currentYear = tm.tm_year + 1900;
        m_currentMonth = tm.tm_mon + 1;
        
        LoadDefaultEvents();
        UpdateCalendar();
    }

    void CalendarPage::PrevMonth_Click(IInspectable const&, RoutedEventArgs const&)
    {
        m_currentMonth--;
        if (m_currentMonth < 1)
        {
            m_currentMonth = 12;
            m_currentYear--;
        }
        UpdateCalendar();
    }

    void CalendarPage::NextMonth_Click(IInspectable const&, RoutedEventArgs const&)
    {
        m_currentMonth++;
        if (m_currentMonth > 12)
        {
            m_currentMonth = 1;
            m_currentYear++;
        }
        UpdateCalendar();
    }

    void CalendarPage::Today_Click(IInspectable const&, RoutedEventArgs const&)
    {
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);
        std::tm tm;
        localtime_s(&tm, &time);
        
        m_currentYear = tm.tm_year + 1900;
        m_currentMonth = tm.tm_mon + 1;
        
        UpdateCalendar();
    }

    void CalendarPage::AddEvent_Click(IInspectable const&, RoutedEventArgs const&)
    {
        auto title = EventTitleBox().Text();
        if (title.empty())
            return;

        CalendarEvent event;
        event.title = std::wstring(title);
        event.type = L"Custom";
        event.year = m_currentYear;
        event.month = m_currentMonth;
        event.day = 15; // Default
        event.hour = 12;
        event.minute = 0;

        m_events.push_back(event);
        UpdateUpcomingEvents();
        
        // Clear input
        EventTitleBox().Text(L"");
    }

    void CalendarPage::UpdateCalendar()
    {
        // Update month text
        const wchar_t* months[] = {
            L"January", L"February", L"March", L"April", L"May", L"June",
            L"July", L"August", L"September", L"October", L"November", L"December"
        };
        
        wchar_t buffer[100];
        swprintf_s(buffer, L"%s %d", months[m_currentMonth - 1], m_currentYear);
        CurrentMonthText().Text(buffer);

        PopulateCalendarGrid();
        UpdateUpcomingEvents();
    }

    void CalendarPage::PopulateCalendarGrid()
    {
        // Clear existing calendar
        CalendarGrid().Children().Clear();
        CalendarGrid().RowDefinitions().Clear();
        CalendarGrid().ColumnDefinitions().Clear();

        // Create 6 rows and 7 columns
        for (int i = 0; i < 6; i++)
        {
            RowDefinition row;
            row.Height(GridLengthHelper::FromValueAndType(1, GridUnitType::Star));
            CalendarGrid().RowDefinitions().Append(row);
        }

        for (int i = 0; i < 7; i++)
        {
            ColumnDefinition col;
            col.Width(GridLengthHelper::FromValueAndType(1, GridUnitType::Star));
            CalendarGrid().ColumnDefinitions().Append(col);
        }

        // Calculate first day of month and days in month
        std::tm firstDay = {};
        firstDay.tm_year = m_currentYear - 1900;
        firstDay.tm_mon = m_currentMonth - 1;
        firstDay.tm_mday = 1;
        std::mktime(&firstDay);
        
        int startDayOfWeek = firstDay.tm_wday;
        
        int daysInMonth = 31;
        if (m_currentMonth == 2)
        {
            bool isLeap = (m_currentYear % 4 == 0 && m_currentYear % 100 != 0) || (m_currentYear % 400 == 0);
            daysInMonth = isLeap ? 29 : 28;
        }
        else if (m_currentMonth == 4 || m_currentMonth == 6 || m_currentMonth == 9 || m_currentMonth == 11)
        {
            daysInMonth = 30;
        }

        // Populate calendar days
        int day = 1;
        for (int row = 0; row < 6 && day <= daysInMonth; row++)
        {
            for (int col = 0; col < 7; col++)
            {
                if (row == 0 && col < startDayOfWeek)
                {
                    continue;
                }
                
                if (day > daysInMonth)
                {
                    break;
                }

                // Create day button
                Border dayBorder;
                dayBorder.BorderBrush(Microsoft::UI::Xaml::Media::SolidColorBrush(Microsoft::UI::Colors::Gray()));
                dayBorder.BorderThickness(ThicknessHelper::FromUniformLength(1));
                dayBorder.Padding(ThicknessHelper::FromUniformLength(8));
                dayBorder.Margin(ThicknessHelper::FromUniformLength(2));

                // Check if there's an event on this day
                bool hasEvent = false;
                for (const auto& event : m_events)
                {
                    if (event.year == m_currentYear && event.month == m_currentMonth && event.day == day)
                    {
                        hasEvent = true;
                        break;
                    }
                }

                if (hasEvent)
                {
                    dayBorder.Background(Microsoft::UI::Xaml::Media::SolidColorBrush(Microsoft::UI::ColorHelper::FromArgb(255, 255, 182, 193)));
                }

                StackPanel dayContent;
                dayContent.Spacing(4);

                TextBlock dayNumber;
                dayNumber.Text(std::to_wstring(day));
                dayNumber.FontSize(16);
                dayNumber.FontWeight(Microsoft::UI::Text::FontWeights::SemiBold());
                
                dayContent.Children().Append(dayNumber);
                dayBorder.Child(dayContent);

                Grid::SetRow(dayBorder, row);
                Grid::SetColumn(dayBorder, col);
                CalendarGrid().Children().Append(dayBorder);

                day++;
            }
        }
    }

    void CalendarPage::UpdateUpcomingEvents()
    {
        UpcomingEventsList().Children().Clear();

        if (m_events.empty())
        {
            TextBlock noEvents;
            noEvents.Text(L"No upcoming events");
            noEvents.Opacity(0.6);
            UpcomingEventsList().Children().Append(noEvents);
            return;
        }

        for (const auto& event : m_events)
        {
            Border eventBorder;
            eventBorder.Background(Microsoft::UI::Xaml::Media::SolidColorBrush(Microsoft::UI::ColorHelper::FromArgb(255, 255, 245, 238)));
            eventBorder.CornerRadius(CornerRadiusHelper::FromUniformRadius(4));
            eventBorder.Padding(ThicknessHelper::FromUniformLength(8));

            StackPanel eventContent;
            eventContent.Spacing(4);

            TextBlock title;
            title.Text(event.title);
            title.FontWeight(Microsoft::UI::Text::FontWeights::SemiBold());

            TextBlock date;
            wchar_t dateStr[50];
            swprintf_s(dateStr, L"📅 %02d/%02d/%04d at %02d:%02d", 
                      event.month, event.day, event.year, event.hour, event.minute);
            date.Text(dateStr);
            date.FontSize(12);
            date.Opacity(0.7);

            TextBlock type;
            type.Text(L"🏷️ " + event.type);
            type.FontSize(12);

            eventContent.Children().Append(title);
            eventContent.Children().Append(date);
            eventContent.Children().Append(type);

            eventBorder.Child(eventContent);
            UpcomingEventsList().Children().Append(eventBorder);
        }
    }

    void CalendarPage::LoadDefaultEvents()
    {
        // Add some default salami-related events
        CalendarEvent event1;
        event1.title = L"Weekly Salami Tasting";
        event1.type = L"Tasting";
        event1.year = m_currentYear;
        event1.month = m_currentMonth;
        event1.day = 15;
        event1.hour = 18;
        event1.minute = 0;
        m_events.push_back(event1);

        CalendarEvent event2;
        event2.title = L"Visit Local Deli";
        event2.type = L"Shopping";
        event2.year = m_currentYear;
        event2.month = m_currentMonth;
        event2.day = 20;
        event2.hour = 14;
        event2.minute = 0;
        m_events.push_back(event2);

        CalendarEvent event3;
        event3.title = L"Try New Salami Recipe";
        event3.type = L"Recipe";
        event3.year = m_currentYear;
        event3.month = m_currentMonth;
        event3.day = 25;
        event3.hour = 12;
        event3.minute = 0;
        m_events.push_back(event3);
    }
}
