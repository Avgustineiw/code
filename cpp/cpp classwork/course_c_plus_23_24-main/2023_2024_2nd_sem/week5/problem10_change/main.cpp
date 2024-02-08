///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
///Write a program that reads a text file, converts all lowercase letters to uppercase, and writes the result to a new file.
///////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>
#include <cctype> // For toupper()

void convertToLowercase(const std::string& inputFilePath, const std::string& outputFilePath)
{
  std::ifstream in(inputFilePath);
  std::ofstream out(outputFilePath);
  std::string arr;

  while (!in.eof()) {
    getline(in, arr);
    
    for (int i = 0; i < arr.length(); i++) {
      arr[i] = toupper(arr[i]);
    }

    out << arr << std::endl;
  }
}


int main() {
  convertToLowercase("input.txt", "output_uppercase.txt");
  return 0;
}
