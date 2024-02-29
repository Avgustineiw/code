#include <iostream>
#include <sstream>
#include <set>
#include <fstream>

int main() 
{
  freopen("input.txt", "r", stdin);

  std::string str, word;
  std::set<std::string> data;

  
  while (std::cin >> word) {
    data.insert(word);
  }

  std::cout << data.size();

  return 0;
}