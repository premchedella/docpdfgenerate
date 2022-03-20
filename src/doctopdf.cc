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

  if (no_args == 3)
  {
    QString input_file_name = QString(argv[1]);

    std::cout << "Input File Name = " << input_file_name.toStdString() 
        << std::endl;

    QString output_dir = QString(argv[2]);

    std::cout << "Output Path = " << output_dir.toStdString() << std::endl;

  } else
  {
    std::cout << "Not valid arguments." << std::endl; 
  }

  core_app.exit();
}
