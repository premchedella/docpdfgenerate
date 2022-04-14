#include "process_data.h"


#include "data_file.h"

ProcessData::ProcessData()
{

}


void ProcessData::SetDataFile(QString file_name)
{
  data_file_ = file_name;
}

void ProcessData::Process()
{
  DataFile data_file(data_file_);

  data_file.Read();

  unsigned int data_cols = data_file.GetDataCols();

}

