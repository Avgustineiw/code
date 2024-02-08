///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Create a function that copies the content of one file to another file.
///
///////////////////////////////////////////////////////////////////////////////
#include <fstream>

void copyFile(const std::string &sourceFilePath,
              const std::string &destinationFilePath) {
  std::ifstream myIN(sourceFilePath);
  std::ofstream myOUT(destinationFilePath);

  while (!myIN.eof()) {
    std::string line;

    getline(myIN, line);
    myOUT << line << std::endl;
  }

  myIN.close();
  myOUT.close();
}


int main() {
  copyFile("source.txt", "destination.txt");

  return 0;
}