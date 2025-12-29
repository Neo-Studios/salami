#pragma once

#include "NotesPage.g.h"
#include <vector>
#include <string>
#include <chrono>

namespace winrt::Salami::implementation
{
    struct Note
    {
        int id;
        std::wstring title;
        std::wstring content;
        std::wstring category;
        std::wstring salamiType;
        std::chrono::system_clock::time_point created;
        std::chrono::system_clock::time_point modified;
        bool isFavorite;
    };

    struct NotesPage : NotesPageT<NotesPage>
    {
        NotesPage();

        void NewNote_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void SaveNote_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void DeleteNote_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void ExportNote_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void NoteTitleBox_TextChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::TextChangedEventArgs const& e);
        void NoteContentBox_TextChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::TextChangedEventArgs const& e);
        void NoteCategoryCombo_SelectionChanged(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs const& e);

    private:
        std::vector<Note> m_notes;
        Note* m_currentNote;
        int m_nextNoteId;
        bool m_isDirty;

        void LoadNotes();
        void SaveNotes();
        void RefreshNotesList();
        void SelectNote(int noteId);
        void CreateNewNote();
        void UpdateLastModified();
        std::wstring FormatDateTime(const std::chrono::system_clock::time_point& time);
    };
}

namespace winrt::Salami::factory_implementation
{
    struct NotesPage : NotesPageT<NotesPage, implementation::NotesPage>
    {
    };
}
