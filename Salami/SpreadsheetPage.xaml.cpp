#include "pch.h"
#include "SpreadsheetPage.xaml.h"
#if __has_include("SpreadsheetPage.g.cpp")
#include "SpreadsheetPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;

namespace winrt::Salami::implementation
{
    SpreadsheetPage::SpreadsheetPage()
    {
        InitializeComponent();
        InitializeSpreadsheet();
        LoadDefaultSheets();
        CreateGrid();
        UpdateStatusBar();
    }

    void SpreadsheetPage::InitializeSpreadsheet()
    {
        m_metadata.filename = L"Untitled.salsheet";
        m_metadata.author = L"Salami Enthusiast";
        m_metadata.created = std::chrono::system_clock::now();
        m_metadata.modified = std::chrono::system_clock::now();
        m_metadata.isModified = false;
        
        m_selectedRow = -1;
        m_selectedCol = -1;
        m_isCalculating = false;
    }

    void SpreadsheetPage::LoadDefaultSheets()
    {
        // Sheet 1: Salami Inventory
        SheetData sheet1;
        sheet1.name = L"Salami Inventory";
        sheet1.rowCount = 100;
        sheet1.columnCount = 26;
        
        // Add headers
        SetCellValue(0, 0, L"Salami Type");
        SetCellValue(0, 1, L"Quantity (lbs)");
        SetCellValue(0, 2, L"Price per lb");
        SetCellValue(0, 3, L"Total Cost");
        SetCellValue(0, 4, L"Purchase Date");
        SetCellValue(0, 5, L"Expiry Date");
        SetCellValue(0, 6, L"Supplier");
        SetCellValue(0, 7, L"Notes");
        
        // Sample data
        SetCellValue(1, 0, L"Genoa Salami");
        SetCellValue(1, 1, L"2.5");
        SetCellValue(1, 2, L"12.99");
        SetCellFormula(1, 3, L"=B2*C2");
        SetCellValue(1, 4, L"2024-01-15");
        SetCellValue(1, 5, L"2024-04-15");
        SetCellValue(1, 6, L"Italian Imports Co.");
        
        SetCellValue(2, 0, L"Soppressata");
        SetCellValue(2, 1, L"1.8");
        SetCellValue(2, 2, L"15.50");
        SetCellFormula(2, 3, L"=B3*C3");
        SetCellValue(2, 4, L"2024-01-20");
        SetCellValue(2, 5, L"2024-04-20");
        SetCellValue(2, 6, L"Tuscan Meats Ltd.");
        
        SetCellValue(3, 0, L"Calabrese");
        SetCellValue(3, 1, L"3.0");
        SetCellValue(3, 2, L"14.25");
        SetCellFormula(3, 3, L"=B4*C4");
        SetCellValue(3, 4, L"2024-01-18");
        SetCellValue(3, 5, L"2024-04-18");
        SetCellValue(3, 6, L"Southern Italian Deli");
        
        SetCellValue(5, 0, L"TOTAL INVENTORY VALUE:");
        SetCellFormula(5, 3, L"=SUM(D2:D4)");
        
        m_sheets.push_back(sheet1);
        
        // Sheet 2: Recipe Cost Calculator
        SheetData sheet2;
        sheet2.name = L"Recipe Costs";
        sheet2.rowCount = 100;
        sheet2.columnCount = 26;
        
        SetCellValue(0, 0, L"Ingredient");
        SetCellValue(0, 1, L"Amount");
        SetCellValue(0, 2, L"Unit");
        SetCellValue(0, 3, L"Cost per Unit");
        SetCellValue(0, 4, L"Total Cost");
        SetCellValue(0, 5, L"Calories");
        SetCellValue(0, 6, L"Protein (g)");
        SetCellValue(0, 7, L"Fat (g)");
        
        m_sheets.push_back(sheet2);
        
        // Sheet 3: Tasting Scorecard
        SheetData sheet3;
        sheet3.name = L"Tasting Scores";
        sheet3.rowCount = 100;
        sheet3.columnCount = 26;
        
        SetCellValue(0, 0, L"Date");
        SetCellValue(0, 1, L"Salami Name");
        SetCellValue(0, 2, L"Producer");
        SetCellValue(0, 3, L"Appearance");
        SetCellValue(0, 4, L"Aroma");
        SetCellValue(0, 5, L"Taste");
        SetCellValue(0, 6, L"Texture");
        SetCellValue(0, 7, L"Overall");
        SetCellValue(0, 8, L"Average Score");
        
        m_sheets.push_back(sheet3);
        
        m_currentSheetIndex = 0;
    }

    void SpreadsheetPage::CreateGrid()
    {
        // Create dynamic grid with row and column headers
        // Implementation would create TextBox controls in a Grid layout
    }

    // File Menu Implementations
    void SpreadsheetPage::New_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_metadata.isModified)
        {
            // Show save prompt
        }
        
        m_sheets.clear();
        LoadDefaultSheets();
        InitializeSpreadsheet();
        UpdateStatusBar();
    }

    void SpreadsheetPage::Open_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Show file picker and load workbook
    }

    void SpreadsheetPage::Save_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_metadata.filename == L"Untitled.salsheet")
        {
            SaveAs_Click(nullptr, nullptr);
        }
        else
        {
            SaveWorkbook();
        }
    }

    void SpreadsheetPage::SaveAs_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Show save dialog
    }

    void SpreadsheetPage::ImportCSV_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Show file picker and import CSV
    }

    void SpreadsheetPage::ExportCSV_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Export current sheet to CSV
        ExportToCSV(m_metadata.filename + L".csv");
    }

    void SpreadsheetPage::ExportPDF_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Export to PDF
    }

    void SpreadsheetPage::Print_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Print current sheet
    }

    void SpreadsheetPage::Close_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_metadata.isModified)
        {
            // Show save prompt
        }
    }

    // Edit Menu Implementations
    void SpreadsheetPage::Undo_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Implement undo
    }

    void SpreadsheetPage::Redo_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Implement redo
    }

    void SpreadsheetPage::Cut_Click(IInspectable const&, RoutedEventArgs const&)
    {
        Copy_Click(nullptr, nullptr);
        Delete_Click(nullptr, nullptr);
    }

    void SpreadsheetPage::Copy_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Copy selected cells to clipboard
    }

    void SpreadsheetPage::Paste_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Paste from clipboard
    }

    void SpreadsheetPage::Delete_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_selectedRow >= 0 && m_selectedCol >= 0)
        {
            ClearCell(m_selectedRow, m_selectedCol);
        }
    }

    void SpreadsheetPage::ClearAll_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Clear all cells in selection
        for (auto& [pos, cell] : m_sheets[m_currentSheetIndex].cells)
        {
            ClearCell(pos.first, pos.second);
        }
    }

    // Insert Menu Implementations
    void SpreadsheetPage::InsertRow_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_selectedRow >= 0)
        {
            InsertRowAt(m_selectedRow);
        }
    }

    void SpreadsheetPage::InsertColumn_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_selectedCol >= 0)
        {
            InsertColumnAt(m_selectedCol);
        }
    }

    void SpreadsheetPage::InsertChart_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Show chart creation dialog
    }

    void SpreadsheetPage::InsertImage_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Insert image into sheet
    }

    void SpreadsheetPage::InsertFunction_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Show function wizard
    }

    // Format Menu Implementations
    void SpreadsheetPage::FormatCells_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Show cell formatting dialog
    }

    void SpreadsheetPage::FormatRows_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Format row height, visibility
    }

    void SpreadsheetPage::FormatColumns_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Format column width, visibility
    }

    void SpreadsheetPage::NumberFormat_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_selectedRow >= 0 && m_selectedCol >= 0)
        {
            ApplyCellFormat(m_selectedRow, m_selectedCol, L"0.00");
        }
    }

    void SpreadsheetPage::DateFormat_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_selectedRow >= 0 && m_selectedCol >= 0)
        {
            ApplyCellFormat(m_selectedRow, m_selectedCol, L"yyyy-MM-dd");
        }
    }

    void SpreadsheetPage::CurrencyFormat_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_selectedRow >= 0 && m_selectedCol >= 0)
        {
            ApplyCellFormat(m_selectedRow, m_selectedCol, L"$#,##0.00");
        }
    }

    void SpreadsheetPage::PercentFormat_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_selectedRow >= 0 && m_selectedCol >= 0)
        {
            ApplyCellFormat(m_selectedRow, m_selectedCol, L"0.00%");
        }
    }

    // Data Menu Implementations
    void SpreadsheetPage::Sort_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Show sort dialog
    }

    void SpreadsheetPage::Filter_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Apply auto-filter to selection
    }

    void SpreadsheetPage::PivotTable_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Create pivot table from selection
    }

    void SpreadsheetPage::DataValidation_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Set up data validation rules
    }

    void SpreadsheetPage::RemoveDuplicates_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Remove duplicate rows
    }

    // Formula Menu Implementations
    void SpreadsheetPage::InsertSUM_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_selectedRow >= 0 && m_selectedCol >= 0)
        {
            SetCellFormula(m_selectedRow, m_selectedCol, L"=SUM()");
        }
    }

    void SpreadsheetPage::InsertAVERAGE_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_selectedRow >= 0 && m_selectedCol >= 0)
        {
            SetCellFormula(m_selectedRow, m_selectedCol, L"=AVERAGE()");
        }
    }

    void SpreadsheetPage::InsertCOUNT_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_selectedRow >= 0 && m_selectedCol >= 0)
        {
            SetCellFormula(m_selectedRow, m_selectedCol, L"=COUNT()");
        }
    }

    void SpreadsheetPage::InsertMAX_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_selectedRow >= 0 && m_selectedCol >= 0)
        {
            SetCellFormula(m_selectedRow, m_selectedCol, L"=MAX()");
        }
    }

    void SpreadsheetPage::InsertMIN_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_selectedRow >= 0 && m_selectedCol >= 0)
        {
            SetCellFormula(m_selectedRow, m_selectedCol, L"=MIN()");
        }
    }

    void SpreadsheetPage::FormulaBuilder_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Show formula builder dialog
    }

    // Salami-Specific Tools
    void SpreadsheetPage::RecipeScaler_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Open recipe scaling calculator
        // Scale ingredients based on servings multiplier
    }

    void SpreadsheetPage::NutritionCalculator_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Calculate nutritional information for salami recipes
        // Per 100g: Calories, Protein, Fat, Carbs, Sodium
    }

    void SpreadsheetPage::PriceComparison_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Compare salami prices across suppliers
        // Calculate best value based on quality and price
    }

    void SpreadsheetPage::ShoppingPlanner_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Plan salami shopping list with budget tracking
    }

    // Sheet Management
    void SpreadsheetPage::AddSheet_Click(IInspectable const&, RoutedEventArgs const&)
    {
        SheetData newSheet;
        newSheet.name = L"Sheet " + std::to_wstring(m_sheets.size() + 1);
        newSheet.rowCount = 100;
        newSheet.columnCount = 26;
        m_sheets.push_back(newSheet);
        m_currentSheetIndex = static_cast<int>(m_sheets.size()) - 1;
        UpdateStatusBar();
    }

    void SpreadsheetPage::DeleteSheet_Click(IInspectable const&, RoutedEventArgs const&)
    {
        if (m_sheets.size() > 1)
        {
            m_sheets.erase(m_sheets.begin() + m_currentSheetIndex);
            m_currentSheetIndex = std::max(0, m_currentSheetIndex - 1);
            UpdateStatusBar();
        }
    }

    void SpreadsheetPage::RenameSheet_Click(IInspectable const&, RoutedEventArgs const&)
    {
        // Show rename dialog
    }

    void SpreadsheetPage::Sheet_SelectionChanged(IInspectable const&, SelectionChangedEventArgs const&)
    {
        // Switch to selected sheet
    }

    // Cell Events
    void SpreadsheetPage::Cell_TextChanged(IInspectable const&, TextChangedEventArgs const&)
    {
        m_metadata.isModified = true;
        RecalculateFormulas();
        UpdateStatusBar();
    }

    void SpreadsheetPage::Cell_GotFocus(IInspectable const&, RoutedEventArgs const&)
    {
        UpdateFormulaBar();
    }

    void SpreadsheetPage::FormulaBar_TextChanged(IInspectable const&, TextChangedEventArgs const&)
    {
        // Update cell from formula bar
    }

    // Private Helper Methods
    void SpreadsheetPage::UpdateFormulaBar()
    {
        if (m_selectedRow >= 0 && m_selectedCol >= 0)
        {
            auto& cell = GetCell(m_selectedRow, m_selectedCol);
            // Update formula bar text
        }
    }

    void SpreadsheetPage::UpdateStatusBar()
    {
        // Update sheet info, cell count, formulas count
    }

    void SpreadsheetPage::RecalculateFormulas()
    {
        if (m_isCalculating) return;
        m_isCalculating = true;
        
        auto& sheet = m_sheets[m_currentSheetIndex];
        for (auto& [pos, cell] : sheet.cells)
        {
            if (cell.hasFormula)
            {
                EvaluateFormula(cell.formula);
            }
        }
        
        m_isCalculating = false;
    }

    void SpreadsheetPage::EvaluateFormula(std::wstring const& formula)
    {
        // Parse and evaluate formula
        double result = ParseFormula(formula);
        // Update cell display value
    }

    double SpreadsheetPage::ParseFormula(std::wstring const& formula)
    {
        // Simple formula parser
        // Handle SUM, AVERAGE, COUNT, MAX, MIN, basic arithmetic
        
        if (formula.find(L"SUM") != std::wstring::npos)
        {
            // Parse SUM(range)
            return 0.0;
        }
        else if (formula.find(L"AVERAGE") != std::wstring::npos)
        {
            // Parse AVERAGE(range)
            return 0.0;
        }
        else if (formula.find(L"COUNT") != std::wstring::npos)
        {
            // Parse COUNT(range)
            return 0.0;
        }
        else if (formula.find(L"MAX") != std::wstring::npos)
        {
            // Parse MAX(range)
            return 0.0;
        }
        else if (formula.find(L"MIN") != std::wstring::npos)
        {
            // Parse MIN(range)
            return 0.0;
        }
        
        // Parse arithmetic expressions
        return 0.0;
    }

    std::wstring SpreadsheetPage::GetCellReference(int row, int col)
    {
        std::wstring ref;
        
        // Convert column to letter(s)
        int tempCol = col;
        while (tempCol >= 0)
        {
            ref = static_cast<wchar_t>(L'A' + (tempCol % 26)) + ref;
            tempCol = tempCol / 26 - 1;
        }
        
        // Add row number (1-based)
        ref += std::to_wstring(row + 1);
        
        return ref;
    }

    std::pair<int, int> SpreadsheetPage::ParseCellReference(std::wstring const& ref)
    {
        // Parse cell reference like "A1" to row, col
        int col = 0;
        int row = 0;
        
        size_t i = 0;
        while (i < ref.length() && std::isalpha(ref[i]))
        {
            col = col * 26 + (ref[i] - L'A' + 1);
            i++;
        }
        col--; // Convert to 0-based
        
        while (i < ref.length() && std::isdigit(ref[i]))
        {
            row = row * 10 + (ref[i] - L'0');
            i++;
        }
        row--; // Convert to 0-based
        
        return { row, col };
    }

    SpreadsheetPage::CellData& SpreadsheetPage::GetCell(int row, int col)
    {
        auto& sheet = m_sheets[m_currentSheetIndex];
        return sheet.cells[{row, col}];
    }

    void SpreadsheetPage::SetCellValue(int row, int col, std::wstring const& value)
    {
        auto& cell = GetCell(row, col);
        cell.rawValue = value;
        cell.displayValue = value;
        cell.hasFormula = false;
        m_metadata.isModified = true;
    }

    void SpreadsheetPage::SetCellFormula(int row, int col, std::wstring const& formula)
    {
        auto& cell = GetCell(row, col);
        cell.formula = formula;
        cell.hasFormula = true;
        cell.rawValue = formula;
        EvaluateFormula(formula);
        m_metadata.isModified = true;
    }

    void SpreadsheetPage::ApplyCellFormat(int row, int col, std::wstring const& format)
    {
        auto& cell = GetCell(row, col);
        cell.format = format;
        // Reformat display value
        m_metadata.isModified = true;
    }

    void SpreadsheetPage::CopyCell(int sourceRow, int sourceCol, int destRow, int destCol)
    {
        auto& source = GetCell(sourceRow, sourceCol);
        auto& dest = GetCell(destRow, destCol);
        dest = source;
    }

    void SpreadsheetPage::ClearCell(int row, int col)
    {
        auto& cell = GetCell(row, col);
        cell.rawValue.clear();
        cell.displayValue.clear();
        cell.formula.clear();
        cell.hasFormula = false;
        m_metadata.isModified = true;
    }

    void SpreadsheetPage::InsertRowAt(int rowIndex)
    {
        auto& sheet = m_sheets[m_currentSheetIndex];
        
        // Shift all rows down
        std::map<std::pair<int, int>, CellData> newCells;
        for (auto& [pos, cell] : sheet.cells)
        {
            if (pos.first >= rowIndex)
            {
                newCells[{pos.first + 1, pos.second}] = cell;
            }
            else
            {
                newCells[pos] = cell;
            }
        }
        sheet.cells = newCells;
        sheet.rowCount++;
    }

    void SpreadsheetPage::InsertColumnAt(int colIndex)
    {
        auto& sheet = m_sheets[m_currentSheetIndex];
        
        // Shift all columns right
        std::map<std::pair<int, int>, CellData> newCells;
        for (auto& [pos, cell] : sheet.cells)
        {
            if (pos.second >= colIndex)
            {
                newCells[{pos.first, pos.second + 1}] = cell;
            }
            else
            {
                newCells[pos] = cell;
            }
        }
        sheet.cells = newCells;
        sheet.columnCount++;
    }

    void SpreadsheetPage::DeleteRowAt(int rowIndex)
    {
        auto& sheet = m_sheets[m_currentSheetIndex];
        
        // Remove row and shift up
        std::map<std::pair<int, int>, CellData> newCells;
        for (auto& [pos, cell] : sheet.cells)
        {
            if (pos.first < rowIndex)
            {
                newCells[pos] = cell;
            }
            else if (pos.first > rowIndex)
            {
                newCells[{pos.first - 1, pos.second}] = cell;
            }
        }
        sheet.cells = newCells;
        sheet.rowCount--;
    }

    void SpreadsheetPage::DeleteColumnAt(int colIndex)
    {
        auto& sheet = m_sheets[m_currentSheetIndex];
        
        // Remove column and shift left
        std::map<std::pair<int, int>, CellData> newCells;
        for (auto& [pos, cell] : sheet.cells)
        {
            if (pos.second < colIndex)
            {
                newCells[pos] = cell;
            }
            else if (pos.second > colIndex)
            {
                newCells[{pos.first, pos.second - 1}] = cell;
            }
        }
        sheet.cells = newCells;
        sheet.columnCount--;
    }

    void SpreadsheetPage::SortRange(int startRow, int startCol, int endRow, int endCol, bool ascending)
    {
        // Implement sorting algorithm
    }

    void SpreadsheetPage::ApplyFilter(int row, int col, std::wstring const& criteria)
    {
        // Implement filtering
    }

    void SpreadsheetPage::CreateChart(std::wstring const& type, int startRow, int startCol, int endRow, int endCol)
    {
        // Create chart from data range
    }

    void SpreadsheetPage::ImportFromCSV(std::wstring const& filepath)
    {
        // Parse CSV and populate cells
    }

    void SpreadsheetPage::ExportToCSV(std::wstring const& filepath)
    {
        // Export current sheet to CSV format
        auto& sheet = m_sheets[m_currentSheetIndex];
        
        std::wofstream file(filepath);
        if (file.is_open())
        {
            for (int row = 0; row < sheet.rowCount; row++)
            {
                for (int col = 0; col < sheet.columnCount; col++)
                {
                    auto& cell = GetCell(row, col);
                    file << L"\"" << cell.displayValue << L"\"";
                    if (col < sheet.columnCount - 1)
                        file << L",";
                }
                file << L"\n";
            }
            file.close();
        }
    }

    void SpreadsheetPage::SaveWorkbook()
    {
        // Serialize and save all sheets
        m_metadata.modified = std::chrono::system_clock::now();
        m_metadata.isModified = false;
    }

    void SpreadsheetPage::LoadWorkbook(std::wstring const& filepath)
    {
        // Deserialize and load workbook
    }
}
