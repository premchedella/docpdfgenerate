#include <iostream>

#include <QtCore/QCoreApplication>
#include <QtCore/QString>

using namespace std;

int main(int argc, char *argv[])
{
  QCoreApplication core_app(argc, argv);

  std::cout << "Convert Document into different PDF files." << std::endl;

  int no_args = argc;

  std::cout << "No. of Arguments = " << no_args << std::endl;

  if (no_args == 5)
  {
    bool is_process = true;

    QString data_file = QString(argv[1]);
    std::cout << "Data File = " << data_file.toStdString() << std::endl;



    QString template_file = QString(argv[2]);
    std::cout << "Template File = " << template_file.toStdString() << std::endl;

    QString replace_file = QString(argv[3]);
    std::cout << "Replacement File = " << replace_file.toStdString() << std::endl;

    QString output_dir = QString(argv[4]);
    std::cout << "Output Path = " << output_dir.toStdString() << std::endl;
  } else
  {
    std::cout << "Not valid arguments." << std::endl; 
  }

  core_app.exit();
}
