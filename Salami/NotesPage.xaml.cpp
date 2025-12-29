#include "pch.h"
#include "NotesPage.xaml.h"
#if __has_include("NotesPage.g.cpp")
#include "NotesPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;

namespace winrt::Salami::implementation
{
    NotesPage::NotesPage()
    {
        InitializeComponent();
        InitializeNotes();
        LoadRecentNotes();
        UpdateNotesList();
    }

    void NotesPage::InitializeNotes()
    {
        m_currentNoteId = -1;
        m_notesModified = false;
    }

    void NotesPage::LoadRecentNotes()
    {
        // Load notes from storage
        
        // Sample note 1: Tasting Notes
        Note note1;
        note1.id = 1;
        note1.title = L"Genoa Salami Tasting - January 2024";
        note1.content = L"Tasted a beautiful Genoa salami from Tuscany today.\n\n"
                       L"Appearance: Deep red color with excellent white marbling.\n"
                       L"Aroma: Strong garlic notes with hint of wine.\n"
                       L"Taste: Complex - starts with garlic, develops into rich pork flavor with wine finish.\n"
                       L"Texture: Firm but not dry, excellent chew.\n\n"
                       L"Rating: 9/10\n"
                       L"Would pair excellently with Chianti and aged Parmesan.";
        note1.category = NoteCategory::TastingNotes;
        note1.salamiType = L"Genoa";
        note1.created = std::chrono::system_clock::now() - std::chrono::hours(48);
        note1.modified = note1.created;
        m_notes.push_back(note1);
        
        // Sample note 2: Recipe
        Note note2;
        note2.id = 2;
        note2.title = L"Salami Carbonara Recipe";
        note2.content = L"Ingredients:\n"
                       L"• 400g spaghetti\n"
                       L"• 150g Italian salami, diced\n"
                       L"• 3 egg yolks + 1 whole egg\n"
                       L"• 100g Pecorino Romano, grated\n"
                       L"• Black pepper\n"
                       L"• Salt for pasta water\n\n"
                       L"Instructions:\n"
                       L"1. Cook pasta in salted boiling water\n"
                       L"2. Crisp salami in dry pan\n"
                       L"3. Mix eggs and cheese\n"
                       L"4. Combine hot pasta with salami\n"
                       L"5. Remove from heat, add egg mixture\n"
                       L"6. Toss quickly, add pepper\n\n"
                       L"Serves 4. Perfect comfort food!";
        note2.category = NoteCategory::Recipe;
        note2.salamiType = L"Italian Salami";
        note2.created = std::chrono::system_clock::now() - std::chrono::hours(120);
        note2.modified = note2.created;
        m_notes.push_back(note2);
        
        // Sample note 3: Shopping List
        Note note3;
        note3.id = 3;
        note3.title = L"Salami Shopping List - Italian Market";
        note3.content = L"To Buy:\n"
                       L"☐ Soppressata (200g) - for charcuterie board\n"
                       L"☐ Cacciatore (150g) - snacking\n"
                       L"☐ Finocchiona (250g) - try something new!\n"
                       L"☐ Parmigiano-Reggiano (300g)\n"
                       L"☐ Olives (mixed)\n"
                       L"☐ Fresh ciabatta\n"
                       L"☐ Fig jam\n\n"
                       L"Budget: $60\n"
                       L"Market: Giovanni's Italian Imports\n"
                       L"Date: Next Saturday";
        note3.category = NoteCategory::Shopping;
        note3.salamiType = L"Various";
        note3.created = std::chrono::system_clock::now() - std::chrono::hours(24);
        note3.modified = note3.created;
        m_notes.push_back(note3);
        
        // Sample note 4: Research
        Note note4;
        note4.id = 4;
        note4.title = L"Salami Curing Research Notes";
        note4.content = L"Key Points on Salami Curing:\n\n"
                       L"Temperature Control:\n"
                       L"• Initial fermentation: 65-75°F (18-24°C)\n"
                       L"• Curing phase: 50-60°F (10-15°C)\n"
                       L"• Critical to maintain consistency\n\n"
                       L"Humidity Requirements:\n"
                       L"• Start: 85-90% RH for first 2 days\n"
                       L"• Curing: 70-75% RH\n"
                       L"• Lower gradually as it ages\n\n"
                       L"Time Frames:\n"
                       L"• Small salamis (1-2 inches): 3-4 weeks\n"
                       L"• Medium (2-3 inches): 6-8 weeks\n"
                       L"• Large (3+ inches): 3-4 months\n\n"
                       L"Weight loss target: 30-40% of original weight\n\n"
                       L"Sources: The Art of Making Fermented Sausages, various artisan producers";
        note4.category = NoteCategory::Research;
        note4.salamiType = L"General";
        note4.created = std::chrono::system_clock::now() - std::chrono::hours(168);
        note4.modified = std::chrono::system_clock::now() - std::chrono::hours(96);
        m_notes.push_back(note4);
        
        // Sample note 5: General
        Note note5;
        note5.id = 5;
        note5.title = L"Salami Festival Planning - April";
        note5.content = L"Planning for the Annual Salami Festival\n\n"
                       L"Date: April 15-17, 2024\n"
                       L"Location: Little Italy, Downtown\n\n"
                       L"Things to Do:\n"
                       L"• Attend salami-making demonstration (Sat 2pm)\n"
                       L"• Try the salami tasting flight (all 3 days)\n"
                       L"• Meet artisan producers\n"
                       L"• Cooking competition on Sunday\n"
                       L"• Buy: Special festival exclusive salami\n\n"
                       L"Vendors to Visit:\n"
                       L"1. Nonna's Traditional Meats\n"
                       L"2. Alpine Charcuterie\n"
                       L"3. Spanish Corner (for chorizo)\n"
                       L"4. The Smoke House\n\n"
                       L"Budget: $150 for samples and purchases\n"
                       L"Going with: Mike and Sarah";
        note5.category = NoteCategory::General;
        note5.salamiType = L"Various";
        note5.created = std::chrono::system_clock::now() - std::chrono::hours(72);
        note5.modified = note5.created;
        m_notes.push_back(note5);
    }

    void NotesPage::UpdateNotesList()
    {
        // Update notes list view
        // Sort by modified date (most recent first)
        std::sort(m_notes.begin(), m_notes.end(), 
                 [](const Note& a, const Note& b) { return a.modified > b.modified; });
    }

    // Event Handlers
    void NotesPage::NewNote_Click(IInspectable const&, RoutedEventArgs const&)
    {
        Note newNote;
        newNote.id = m_notes.empty() ? 1 : m_notes.back().id + 1;
        newNote.title = L"Untitled Note";
        newNote.content = L"";
        newNote.category = NoteCategory::General;
        newNote.salamiType = L"";
        newNote.created = std::chrono::system_clock::now();
        newNote.modified = newNote.created;
        
        m_notes.push_back(newNote);
        m_currentNoteId = newNote.id;
        m_notesModified = false;
        
        UpdateNotesList();
        LoadNote(newNote.id);
    }

    void NotesPage::SaveNote_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_currentNoteId >= 0)
        {
            SaveCurrentNote();
            m_notesModified = false;
        }
    }

    void NotesPage::DeleteNote_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_currentNoteId >= 0)
        {
            auto it = std::find_if(m_notes.begin(), m_notes.end(),
                                  [this](const Note& n) { return n.id == m_currentNoteId; });
            
            if (it != m_notes.end())
            {
                m_notes.erase(it);
                m_currentNoteId = -1;
                m_notesModified = false;
                UpdateNotesList();
                
                // Load first note or show empty state
                if (!m_notes.empty())
                {
                    LoadNote(m_notes[0].id);
                }
            }
        }
    }

    void NotesPage::ExportNote_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_currentNoteId >= 0)
        {
            ExportCurrentNote();
        }
    }

    void NotesPage::CategoryFilter_SelectionChanged(IInspectable const& sender, SelectionChangedEventArgs const&)
    {
        if (auto combo = sender.try_as<ComboBox>())
        {
            int selectedIndex = combo.SelectedIndex();
            FilterNotesByCategory(static_cast<NoteCategory>(selectedIndex));
        }
    }

    void NotesPage::SalamiTypeTag_TextChanged(IInspectable const& sender, TextChangedEventArgs const&)
    {
        if (m_currentNoteId >= 0)
        {
            auto it = std::find_if(m_notes.begin(), m_notes.end(),
                                  [this](const Note& n) { return n.id == m_currentNoteId; });
            
            if (it != m_notes.end())
            {
                if (auto textBox = sender.try_as<TextBox>())
                {
                    it->salamiType = textBox.Text();
                    m_notesModified = true;
                }
            }
        }
    }

    void NotesPage::NoteEditor_TextChanged(IInspectable const&, RoutedEventArgs const&)
    {
        m_notesModified = true;
        
        if (m_currentNoteId >= 0)
        {
            auto it = std::find_if(m_notes.begin(), m_notes.end(),
                                  [this](const Note& n) { return n.id == m_currentNoteId; });
            
            if (it != m_notes.end())
            {
                it->modified = std::chrono::system_clock::now();
            }
        }
    }

    void NotesPage::NotesList_SelectionChanged(IInspectable const&, SelectionChangedEventArgs const&)
    {
        // Load selected note
        if (m_notesModified)
        {
            // Prompt to save changes
            SaveCurrentNote();
        }
        
        // Get selected note ID and load it
        // LoadNote(selectedNoteId);
    }

    // Private Methods
    void NotesPage::LoadNote(int noteId)
    {
        auto it = std::find_if(m_notes.begin(), m_notes.end(),
                              [noteId](const Note& n) { return n.id == noteId; });
        
        if (it != m_notes.end())
        {
            m_currentNoteId = noteId;
            
            // Update UI with note data
            // Set title text box
            // Set category combo box
            // Set salami type text box
            // Set editor content
            // Update last modified label
            
            m_notesModified = false;
        }
    }

    void NotesPage::SaveCurrentNote()
    {
        if (m_currentNoteId < 0) return;
        
        auto it = std::find_if(m_notes.begin(), m_notes.end(),
                              [this](const Note& n) { return n.id == m_currentNoteId; });
        
        if (it != m_notes.end())
        {
            // Get current values from UI
            // Update note object
            it->modified = std::chrono::system_clock::now();
            
            // Persist to storage
            SaveNotesToFile();
            
            m_notesModified = false;
            UpdateNotesList();
        }
    }

    void NotesPage::ExportCurrentNote()
    {
        auto it = std::find_if(m_notes.begin(), m_notes.end(),
                              [this](const Note& n) { return n.id == m_currentNoteId; });
        
        if (it != m_notes.end())
        {
            // Export note to file
            std::wstring filename = it->title + L".txt";
            
            // Create file and write content
            std::wofstream file(filename);
            if (file.is_open())
            {
                file << L"Title: " << it->title << L"\n";
                file << L"Category: " << CategoryToString(it->category) << L"\n";
                file << L"Salami Type: " << it->salamiType << L"\n";
                file << L"Created: " << FormatDateTime(it->created) << L"\n";
                file << L"Modified: " << FormatDateTime(it->modified) << L"\n";
                file << L"\n---\n\n";
                file << it->content;
                file.close();
            }
        }
    }

    void NotesPage::FilterNotesByCategory(NoteCategory category)
    {
        // Filter notes list by category
        // Update notes list view to show only matching notes
    }

    void NotesPage::SaveNotesToFile()
    {
        // Serialize all notes to persistent storage
        // Could use JSON, XML, or binary format
    }

    void NotesPage::LoadNotesFromFile()
    {
        // Deserialize notes from persistent storage
    }

    std::wstring NotesPage::CategoryToString(NoteCategory category)
    {
        switch (category)
        {
        case NoteCategory::Recipe: return L"Recipe";
        case NoteCategory::TastingNotes: return L"Tasting Notes";
        case NoteCategory::Shopping: return L"Shopping";
        case NoteCategory::Research: return L"Research";
        case NoteCategory::General: return L"General";
        default: return L"General";
        }
    }

    std::wstring NotesPage::FormatDateTime(std::chrono::system_clock::time_point timePoint)
    {
        auto time = std::chrono::system_clock::to_time_t(timePoint);
        std::wstringstream ss;
        ss << std::put_time(std::localtime(&time), L"%Y-%m-%d %H:%M");
        return ss.str();
    }
}
