///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function to find and replace all occurrences of a word in a file.
///
///////////////////////////////////////////////////////////////////////////////

#include <fstream> // For fstream
#include <sstream> // For stringstream

void findAndReplaceInFile(const std::string& filePath, 
                          const std::string& toFind, 
                          const std::string& toReplace)
{
  std::ifstream myIN(filePath);
  std::ofstream myOUT("output.txt");

  std::string tmp;

  while (!myIN.eof()) {
    getline(myIN, tmp);
    
    while(tmp.find(toFind) != std::string::npos) {
      int pos = tmp.find(toFind);
      tmp.replace(pos, toFind.length(), toReplace);
    }
    myOUT << tmp << std::endl;
  }

  myIN.clear();
  myOUT.clear();
  myIN.close();
  myOUT.close();
  
  myIN.open("output.txt");
  myOUT.open(filePath);

  while (!myIN.eof()) {
    std::string line;

    getline(myIN, line);
    myOUT << line << std::endl;
  }

  //Код работает, но создает пустые строки в обновленном
  //файле. Я не знаю, как это пофиксить.

  myIN.close();
  myOUT.close();
  std::remove("output.txt");
}

int main() {
    findAndReplaceInFile("file.txt", "oldWord", "newWord");
    return 0;
}