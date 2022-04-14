#include <iostream>

#include <QtWidgets/QApplication>
#include <QtCore/QString>

#include "utilities.h"
#include "process_data.h"

using namespace std;


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  std::cout << "Convert Document into different PDF files." << std::endl;  

  int no_args = argc;

  std::cout << "No. of Arguments = " << no_args << std::endl;

  if (no_args == 5)
  {
    bool is_process = true;

    // Get the Data file
    QString data_file = QString(argv[1]);
    std::cout << "Data File = " << data_file.toStdString() << std::endl;

    // Validate the Data file
    if (!Utilities::IsValidDataFile(data_file))
    {
      is_process = false;
    }

    // Get the template file
    QString template_file = QString(argv[2]);
    std::cout << "Template File = " << template_file.toStdString() << std::endl;

    // Validate Template file
    if (!Utilities::IsValidTemplateFile(template_file))
    {
      is_process = false;
    }

    // Get the Replace Text file
    QString replace_file = QString(argv[3]);    
    std::cout << "Replacement File = " << replace_file.toStdString() << std::endl;

    // Validate Replace file
    if (!Utilities::IsValidReplaceFile(replace_file))
    {
      is_process = false;
    }

    // Get the Ouptut Directory
    QString output_dir = QString(argv[4]);
    std::cout << "Output Path = " << output_dir.toStdString() << std::endl;

    // Validate the Output Directory
    if (!Utilities::IsValidOutputPath(output_dir))
    {
      is_process = false;
    }

    if (is_process)
    {
      ProcessData process_data;

      process_data.SetDataFile(data_file);
      process_data.Process();
    }
  } else
  {
    std::cout << "Not valid arguments." << std::endl; 
  }


  QString word_path = Utilities::GetWordPath();

  app.exit();
}


