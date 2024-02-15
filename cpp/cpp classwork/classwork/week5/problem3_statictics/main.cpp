///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program to count the number of lines, words, and characters in a text file.
///
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <sstream> 

void countFileStatistics(const std::string& filePath)
{
  std::ifstream myIN(filePath);
  
  std::string tmp;
  int lines = 0, words = 0, chars = 0;

  while(!myIN.eof()) {
    getline(myIN, tmp);
    lines++;
  }

  myIN.clear();
  myIN.seekg(0);

  while(!myIN.eof()) {
    myIN >> tmp;
    words++;
    chars += tmp.length();
  }

  myIN.close();

  std::cout << lines << " " << words << " " << chars;  
}


int main() {
    countFileStatistics("file.txt");
    return 0;
}