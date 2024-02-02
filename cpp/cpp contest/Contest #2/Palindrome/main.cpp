#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>

bool palindrome(std::string str)
{
  str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
  std::string rev = str;
  std::reverse(rev.begin(), rev.end());

  int i = 0;

  while (i < str.length()) {
    if (str[i] != rev[i]) {
      return false;
    }
    i++;
  }
  return true;
}

int main()
{
  std::string str;

  getline(std::cin, str);

  if (palindrome(str)) {
    std::cout << "yes";
  }
  else {
    std::cout << "no";
  }
  return 0;
}