#include "data_file.h"


DataFile::DataFile(QString file_name)
{
  file_name_ = file_name;
}

void DataFile::Read()
{
  QAxObject* excel = new QAxObject("Excel.Application", 0);
  QAxObject* workbooks = excel->querySubObject("Workbooks");
  QAxObject* workbook = workbooks->querySubObject("Open(const QString&)", file_name_);
  QAxObject* sheets = workbook->querySubObject("Worksheets");
  int count = sheets->dynamicCall("Count()").toInt();

  // Need only first sheet.
  QAxObject* sheet = sheets->querySubObject("Item( int )", 1);
  QAxObject* rows = sheet->querySubObject("Rows");
  int row_count = rows->dynamicCall("Count()").toInt();
  //unfortunately, always returns 1048576, so somehow validity of cell values
  QAxObject* columns = sheet->querySubObject("Columns");
  int column_count = columns->dynamicCall("Count()").toInt();

  //One of possible ways to get column count
  data_cols_ = 0;
  for (int col = 1; col < column_count; col++)
  {
    QAxObject* cell = sheet->querySubObject("Cells( int, int )", 1, col);
    QVariant value = cell->dynamicCall("Value()");
    if (value.toString().isEmpty())
      break;
    else
      data_cols_ = col;
  }

  int data_rows = 0;
  for (int row = 1; row < row_count; row++)
  {
    QAxObject* cell = sheet->querySubObject("Cells( int, int )", row, 1);
    QVariant value = cell->dynamicCall("Value()");
    if (value.toString().isEmpty())
      break;
    else
      data_rows = row;
  }

  data_.clear();

  //For loop should not start with 0 since row 0 and column 0 are not valid.
  for (int row = 1; row <= data_rows; row++)
  {
    QVariantList data_row;

    for (int column = 1; column <= data_cols_; column++)
    {
      QAxObject* cell = sheet->querySubObject("Cells( int, int )", row, column);
      QVariant value = cell->dynamicCall("Value()");
      data_row.append(value);
    }

    data_.append(data_row);
  }

  workbook->dynamicCall("Close()");
  excel->dynamicCall("Quit()");

  std::cout << "Number of Participants " << (data_.size() - 1) << std::endl;
}

QList<QVariantList> DataFile::GetData()
{
  return data_;
}

unsigned int DataFile::GetDataCols()
{
  return data_cols_;
}