#include <iostream>

#include <QtCore/QCoreApplication>

using namespace std;

int main(int argc, char *argv[])
{
  QCoreApplication core_app(argc, argv);

  std::cout << "Convert Document into different PDF files." << std::endl;

  std::cout << "No. of Arguments = " << argc << std::endl;

  core_app.exit();
}
