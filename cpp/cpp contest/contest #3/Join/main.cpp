#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>

std::string join(const std::vector<std::string>& tokens, char delimiter)
{
  std::string res;
  for (int i = 0; i < tokens.size(); i++) {
    res+= tokens[i];
    if (i != tokens.size()-1) {
      res+= delimiter;
    }
  }
  
  return res;
}


int main()
{
  
  std::vector<std::string> tokens;
  std::string tmp, res;
  int n;
  char delimiter;

  std::cin >> n;

  for (int i = 0; i < n; i++)
  {
    std::cin >> tmp;
    tokens.push_back(tmp);
  }

  std::cin >> delimiter;

  std::cout << join(tokens, delimiter);  

  return 0;
}