#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <fstream>

std::string ExtractDigits(const std::string& s) {
  std::string res;

  for (int i = 0; i < s.length(); i++)
  {
    if (int(s[i]) > 47 && int(s[i]) < 58) {
      res += s[i];
    }
  }
  
  return res;
}


int main()
{
  std::string s;

  getline(std::cin, s);

  std::cout << ExtractDigits(s);

  return 0;
}