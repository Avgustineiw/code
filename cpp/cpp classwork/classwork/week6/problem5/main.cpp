///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a program that reads information about company employees (name, position, salary) 
/// from a text file and increases the salary of each employee by 10%, writing the updated 
/// information to a new file.
/// Write two functions: for txt and csv file.
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

void reverseFileContent(const std::string& inputFilePath, const std::string& outputFilePath);


void reverseFileContent(const std::string& inputFilePath, const std::string& outputFilePath)
{
  std::ifstream myIN(inputFilePath);
  std::ofstream myOUT(outputFilePath);
  std::string line, word;
  int cnt = 0, salary;

  while (!myIN.eof()) {
    getline(myIN, line);
    std::stringstream iss(line);

    while (getline(iss, word, ',')) {
      if (cnt < 2) {
        myOUT << word << ",";
        cnt++;
      }
      else {
        salary = (stoi(word) * 1.1);
        myOUT << salary;
        cnt = 0;
      }
    }
    myOUT << "\n";
  }
}


int main() 
{
  reverseFileContent("input.txt", "output_reversed.txt");
  
  return 0;
}