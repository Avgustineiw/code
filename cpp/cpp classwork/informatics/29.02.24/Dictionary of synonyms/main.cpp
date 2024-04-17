#include <iostream>
#include <map>

int main() 
{
  int n;

  std::cin >> n;
  std::map<std::string, std::string> data;
  std::string word_1, word_2;

  for (int i = 0; i < n; i++) {
    std::cin >> word_1 >> word_2;
    data[word_1] = word_2;
    data[word_2] = word_1;
  }
  
  std::string res;
  std::cin >> res;
  std::cout << data[res] << '\n';

  return 0;
}
