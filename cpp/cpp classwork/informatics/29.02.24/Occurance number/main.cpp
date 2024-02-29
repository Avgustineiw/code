#include <iostream>
#include <sstream>
#include <map>
#include <fstream>

int main() 
{
  freopen("input.txt", "r", stdin);

  std::map<std::string, int> data;
  std::string str, word;
  
  while (std::cin >> word) {
    if (data.find(word) == data.end()) {
      std::cout << "0" << " ";
      data[word]++;
    }
    else {
      std::cout << data[word] << " ";
      data[word]++;
    }
  }

  return 0;
}