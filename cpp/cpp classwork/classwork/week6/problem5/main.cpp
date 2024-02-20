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
  int salary;

  char del = ' ';
  std::string s = inputFilePath.substr(inputFilePath.size()-3, 3);
  std::cout << s << std::endl;
  if ( s == "csv") { 
    del = ',';
  }

  while (!myIN.eof()) {
    getline(myIN, line);
    std::stringstream iss(line);

    std::string name, position, ssalary;
    getline(iss, name, del); 
    
    getline(iss, position, del); 
    
    getline(iss, ssalary, del); 
    
    salary = (atoi(ssalary.c_str()) * 1.1);
    myOUT <<name << del << position << del << salary;
    myOUT << "\n";
  }
  myIN.close();
  myOUT.close();
}


int main() 
{
  reverseFileContent("input.csv", "output_reversed.txt");
  
  return 0;
}