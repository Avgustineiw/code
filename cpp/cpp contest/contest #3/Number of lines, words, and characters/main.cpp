#include <fstream>
#include <iostream>
#include <sstream> 

void countFileStatistics(const std::string& filePath, int &chars, int &words, int &lines)
{
  std::ifstream in(filePath);
  char ch;
  bool word_flag = false;

  while (in >> std::noskipws >> ch) {
    if ((int(ch) > 64 && int(ch) < 91) || 
        (int(ch) > 96 && int(ch) < 123)) {
      chars++;
      word_flag = true;
    }
    else {
      if (word_flag) {
        words++;
      }
      word_flag = false;
    }

    if (ch == '\n') {
      lines++;
    }
  }

  in.close();
}


int main() {
  int chars = 0, words = 0, lines = 0;
  countFileStatistics("input.txt", chars, words, lines);
  
  std::cout << "Input file contains: " << std::endl;
  std::cout << chars << " letters" << std::endl;
  std::cout << words << " words" << std::endl;
  std::cout << lines << " lines"; 
  return 0;
}