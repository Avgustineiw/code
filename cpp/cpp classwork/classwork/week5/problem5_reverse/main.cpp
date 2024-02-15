///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a program to read the content of a text file and write its content in reverse order to another file.
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

void reverseFileContent(const std::string& inputFilePath, const std::string& outputFilePath)
{
  std::ifstream myIN(inputFilePath);
  std::fstream myOUT(outputFilePath);

  std::string tmp;
  std::vector<std::string> stor;

  while (!myIN.eof()) {
    getline(myIN, tmp);

    reverse(tmp.begin(), tmp.end());

    stor.push_back(tmp);
  }

  for (int i = stor.size()-1; i >= 0; i--) {
    myOUT << stor[i] << std::endl;
    std::cout << stor[i] << std::endl;
  }
  

  myIN.close();
  myOUT.close();
}


int main() {
    reverseFileContent("input.txt", "output_reversed.txt");

    return 0;
}