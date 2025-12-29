#pragma once
#include "SpreadsheetPage.g.h"
#include <vector>
#include <string>
#include <map>
#include <chrono>

namespace winrt::Salami::implementation
{
    struct SpreadsheetPage : SpreadsheetPageT<SpreadsheetPage>
    {
        SpreadsheetPage();

        // File Menu
        void New_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Open_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Save_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void SaveAs_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void ImportCSV_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void ExportCSV_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void ExportPDF_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Print_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Close_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

        // Edit Menu
        void Undo_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Redo_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Cut_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Copy_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Paste_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Delete_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void ClearAll_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

        // Insert Menu
        void InsertRow_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void InsertColumn_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void InsertChart_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void InsertImage_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void InsertFunction_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

        // Format Menu
        void FormatCells_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void FormatRows_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void FormatColumns_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void NumberFormat_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void DateFormat_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void CurrencyFormat_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void PercentFormat_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

        // Data Menu
        void Sort_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Filter_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void PivotTable_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void DataValidation_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void RemoveDuplicates_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

        // Formulas Menu
        void InsertSUM_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void InsertAVERAGE_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void InsertCOUNT_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void InsertMAX_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void InsertMIN_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void FormulaBuilder_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

        // Tools Menu
        void RecipeScaler_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void NutritionCalculator_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void PriceComparison_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void ShoppingPlanner_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);

        // Sheet Management
        void AddSheet_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void DeleteSheet_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void RenameSheet_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Sheet_SelectionChanged(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs const& args);

        // Cell Events
        void Cell_TextChanged(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::Controls::TextChangedEventArgs const& args);
        void Cell_GotFocus(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void FormulaBar_TextChanged(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::Controls::TextChangedEventArgs const& args);

    private:
        struct CellData
        {
            std::wstring rawValue;
            std::wstring displayValue;
            std::wstring formula;
            bool hasFormula{ false };
            std::wstring format;
            Microsoft::UI::Xaml::Media::Brush background{ nullptr };
            Microsoft::UI::Xaml::Media::Brush foreground{ nullptr };
            std::wstring fontFamily;
            double fontSize{ 11.0 };
            bool bold{ false };
            bool italic{ false };
            bool underline{ false };
        };

        struct SheetData
        {
            std::wstring name;
            std::map<std::pair<int, int>, CellData> cells;
            int rowCount{ 100 };
            int columnCount{ 26 };
        };

        struct WorkbookMetadata
        {
            std::wstring filename{ L"Untitled.salsheet" };
            std::wstring author;
            std::chrono::system_clock::time_point created;
            std::chrono::system_clock::time_point modified;
            bool isModified{ false };
        };

        // Private methods
        void InitializeSpreadsheet();
        void CreateGrid();
        void LoadDefaultSheets();
        void UpdateFormulaBar();
        void UpdateStatusBar();
        void RecalculateFormulas();
        void EvaluateFormula(std::wstring const& formula);
        double ParseFormula(std::wstring const& formula);
        std::wstring GetCellReference(int row, int col);
        std::pair<int, int> ParseCellReference(std::wstring const& ref);
        CellData& GetCell(int row, int col);
        void SetCellValue(int row, int col, std::wstring const& value);
        void SetCellFormula(int row, int col, std::wstring const& formula);
        void ApplyCellFormat(int row, int col, std::wstring const& format);
        void CopyCell(int sourceRow, int sourceCol, int destRow, int destCol);
        void ClearCell(int row, int col);
        void InsertRowAt(int rowIndex);
        void InsertColumnAt(int colIndex);
        void DeleteRowAt(int rowIndex);
        void DeleteColumnAt(int colIndex);
        void SortRange(int startRow, int startCol, int endRow, int endCol, bool ascending);
        void ApplyFilter(int row, int col, std::wstring const& criteria);
        void CreateChart(std::wstring const& type, int startRow, int startCol, int endRow, int endCol);
        void ImportFromCSV(std::wstring const& filepath);
        void ExportToCSV(std::wstring const& filepath);
        void SaveWorkbook();
        void LoadWorkbook(std::wstring const& filepath);

        // Member variables
        std::vector<SheetData> m_sheets;
        int m_currentSheetIndex{ 0 };
        WorkbookMetadata m_metadata;
        int m_selectedRow{ -1 };
        int m_selectedCol{ -1 };
        std::vector<std::pair<int, int>> m_selectedRange;
        bool m_isCalculating{ false };
    };
}

namespace winrt::Salami::factory_implementation
{
    struct SpreadsheetPage : SpreadsheetPageT<SpreadsheetPage, implementation::SpreadsheetPage>
    {
    };
}
