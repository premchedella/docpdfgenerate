#include <iostream>

#include <QtCore/QCoreApplication>
#include <QtCore/QString>
#include <QtCore/QFileInfo>
#include <QtCore/QDir>

using namespace std;

bool IsValidDataFile(QString file_name);
bool IsValidTemplateFile(QString file_name);
bool IsValidReplaceFile(QString file_name);
bool IsValidOutputPath(QString dir_path);

int main(int argc, char *argv[])
{
  QCoreApplication core_app(argc, argv);

  std::cout << "Convert Document into different PDF files." << std::endl;

  int no_args = argc;

  std::cout << "No. of Arguments = " << no_args << std::endl;

  if (no_args == 5)
  {
    bool is_process = true;

    // Get the Data file
    QString data_file = QString(argv[1]);
    std::cout << "Data File = " << data_file.toStdString() << std::endl;

    if (!IsValidDataFile(data_file))
    {
      is_process = false;
    }

    QString template_file = QString(argv[2]);
    std::cout << "Template File = " << template_file.toStdString() << std::endl;

    if (!IsValidTemplateFile(template_file))
    {
      is_process = false;
    }

    QString replace_file = QString(argv[3]);    
    std::cout << "Replacement File = " << replace_file.toStdString() << std::endl;

    if (!IsValidReplaceFile(replace_file))
    {
      is_process = false;
    }

    QString output_dir = QString(argv[4]);
    std::cout << "Output Path = " << output_dir.toStdString() << std::endl;

    if (!IsValidOutputPath(output_dir))
    {
      is_process = false;
    }
  } else
  {
    std::cout << "Not valid arguments." << std::endl; 
  }

  core_app.exit();
}


bool IsValidDataFile(QString file_name)
{
  bool is_valid = true;

  //Check whether Data file exists or not
  QFileInfo fi(file_name);

  if (fi.exists())
  {
    //Get the Extension of file

    QString ext = fi.suffix();
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

bool IsValidTemplateFile(QString file_name)
{
  bool is_valid = false;
  //Check whether Data file exists or not
  QFileInfo fi(file_name);

  if (fi.exists())
  {
    is_valid = true;
    //Get the Extension of file

    QString ext = fi.suffix();
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

bool IsValidReplaceFile(QString file_name)
{
  bool is_valid = true;

  //Check whether Data file exists or not
  QFileInfo fi(file_name);

  if (fi.exists())
  {
    //Get the Extension of file

    QString ext = fi.suffix();
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

bool IsValidOutputPath(QString dir_path)
{
  bool is_valid = false;

  //Check whether Data file exists or not
  QFileInfo dir(dir_path);

  if (dir.isDir())  
  {
    is_valid = true;
  } else
  {    
    std::cout << "Output is not a directory." << std::endl;
  }

  return is_valid;
}