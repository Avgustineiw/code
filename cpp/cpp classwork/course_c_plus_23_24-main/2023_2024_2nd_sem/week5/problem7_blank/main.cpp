///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a program that removes all blank lines from a text file and writes the result to a new file.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>


void removeBlank(const std::string& inputFilePath, 
                 const std::string& outputFilePath)
{
  std::ifstream myIN(inputFilePath);
  std::ofstream myOUT(outputFilePath);
  std::string temp;

  while (!myIN.eof()) {
    getline(myIN, temp);

    if (!temp.empty()) {
      myOUT << temp << std::endl;
    }
  }

  myIN.close();
  myOUT.close();
}


int main()
{
  removeBlank("input.txt", "output.txt");

  return 0;
}
