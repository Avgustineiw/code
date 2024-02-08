#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>

std::vector<std::string> split(const std::string& str, char delimiter)
{
  std::vector<std::string> res;
  std::string tmp;
  int pos = 0, len = -1;

  for (int i = 0; i < str.length() + 1; i++) {
    len++;
    if (str[i] == delimiter || i == str.length()) {
      res.push_back(str.substr(pos, len));
      len = -1;
      pos = i + 1;
    }
  }

  return res;
}


int main()
{
  std::string s;
  char delimiter;

  std::cin >> s >> delimiter;

  std::vector<std::string> res = split(s, delimiter);

  for (std::string i: res) {
    std::cout << i << std::endl;
  }
  

  return 0;
}