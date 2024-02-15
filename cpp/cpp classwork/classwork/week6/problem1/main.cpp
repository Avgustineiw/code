///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       14.02.2024
///
/// TASK DESCRIPTION
///
/// Write a function to read a file containing integers 
/// separated by spaces or newlines, sum these integers, 
/// and write the result to another file.
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>

void sumIntegersInFile(const std::string& inputFilePath, const std::string& outputFilePath);

void sumIntegersInFile(const std::string& inputFilePath, const std::string& outputFilePath) 
{
  int res = 0, tmp;
  std::ifstream myIN(inputFilePath);
  std::ofstream myOUT(outputFilePath);

  while (!myIN.eof()) {
      myIN >> tmp;
      res += tmp;
  }
  
  myOUT << res;
}


int main() 
{
  sumIntegersInFile("input.txt", "output.txt");

  return 0;
}