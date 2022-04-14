#pragma once

#include <iostream>

#include <QtCore\QString>


using namespace std;

class ProcessData
{
 public:
  ProcessData();
  void SetDataFile(QString file_name);

  void Process();
  

 private:  
  QString data_file_;
};

