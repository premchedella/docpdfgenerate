#pragma once

#include <iostream>

#include <QtCore/QString>

class Utilities
{
 public:
  static bool IsValidDataFile(QString file_name);
  static bool IsValidTemplateFile(QString file_name);
  static bool IsValidReplaceFile(QString file_name);
  static bool IsValidOutputPath(QString dir_path);

  static QString GetWordPath();
};


