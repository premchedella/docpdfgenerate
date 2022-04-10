#include "utilities.h"

#include <QtCore/QFileInfo>
#include <QtCore/QDir>
#include <QtCore/QProcess>
#include <QtCore/QSettings>

bool Utilities::IsValidDataFile(QString file_name)
{
  bool is_valid = true;
  QFileInfo fi(file_name);

  // Check whether Data file exists or not
  if (fi.exists())
  {
    // Get the Extension of file
    QString ext = fi.suffix();

    // The Data file extensions is always csv
    if (ext.compare("csv") != 0)
    {
      is_valid = false;
      std::cout << "Data file extension is not in csv file format." << std::endl;
    }
  } else
  {
    is_valid = false;
    std::cout << "Data file doest not exists." << std::endl;
  }

  return is_valid;
}

bool Utilities::IsValidTemplateFile(QString file_name)
{
  bool is_valid = false;
  QFileInfo fi(file_name);

  //Check whether Data file exists or not
  if (fi.exists())
  {
    // Get the Extension of file
    QString ext = fi.suffix();

    // The template file's extension is always doc or docx
    if ((ext.compare("doc") == 0) || (ext.compare("docx") == 0))
    {
      is_valid = true;
    } else
    {
      is_valid = false;
      std::cout << "Template file extension is not in correct format." << std::endl;
    }

  } else
  {
    is_valid = false;
    std::cout << "Template file doest not exists." << std::endl;
  }

  return is_valid;
}

bool Utilities::IsValidReplaceFile(QString file_name)
{
  bool is_valid = true;
  QFileInfo fi(file_name);

  // Check whether Data file exists or not
  if (fi.exists())
  {
    // Get the Extension of file
    QString ext = fi.suffix();

    // The replacement file extension is alwys txt
    if (ext.compare("txt") != 0)
    {
      is_valid = false;
      std::cout << "Replace file extension is not in txt file format." << std::endl;
    }
  } else
  {
    is_valid = false;
    std::cout << "Repalce file doest not exists." << std::endl;
  }

  return is_valid;
}

bool Utilities::IsValidOutputPath(QString dir_path)
{
  bool is_valid = false;
  QFileInfo dir(dir_path);

  // Check whether the output directory is directory or not
  if (dir.isDir())
  {
    is_valid = true;
  } else
  {
    std::cout << "Output is not a directory." << std::endl;
  }

  return is_valid;
}

QString Utilities::GetWordPath()
{
  QString word_path = "";

  // Create Setting path variable to gt the word path
  QString path = "HKEY_LOCAL_MACHINE/SOFTWARE/Microsoft/Windows/";
  path += "CurrentVersion/App Paths/Winword.exe";

  path = QDir::toNativeSeparators(path);
  QSettings settings(path, QSettings::NativeFormat);

  // . is default, so use that to get the value of the default.
  word_path = settings.value(".").toString();

  return word_path;
}