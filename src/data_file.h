#pragma once

#include <iostream>

#include <ActiveQt\QAxObject>
#include <QtCore\QString>
#include <QtCore\QList>

using namespace std;

class DataFile
{
 public:
  DataFile(QString file_name);
  void Read();
  QList<QVariantList> GetData();
  unsigned int GetDataCols();

 private:
  QList<QVariantList> data_;
  unsigned int data_cols_;
  QString file_name_;
};

