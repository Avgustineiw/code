///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function to read a file containing integers
/// separated by spaces or newlines, sum these integers, and write the result to
/// another file.
///////////////////////////////////////////////////////////////////////////////

#include <cmath>
#include <fstream>
#include <iostream>

void sumIntegersInFile(const std::string &inputFilePath,
                       const std::string &outputFilePath) {

  std::ifstream myIN(inputFilePath);
  std::ofstream myOUT(outputFilePath);

  int res = 0;

  while (!myIN.eof()) {
    int num = 0;

    if (myIN >> num) {
      res += num;
    }
  }

  myOUT << res;
  myIN.close();
  myOUT.close();
  return;
}

int main() {
  sumIntegersInFile("input.txt", "output.txt");

  return 0;
}
