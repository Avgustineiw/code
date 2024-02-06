#include <iostream>
#include <stdlib.h>
#include <string>

int countNumbers(std::string str, int &res, int &pos)
{
  if (pos > str.length()) {
    return res;
  }
  else if (isdigit(str[pos])) {
    res++;
    pos++;
    return countNumbers(str, res, pos);
  }
  else {
    pos++;
    return countNumbers(str, res, pos);
  }
}

int main()
{
  std::string str;
  int res = 0, pos = 0;

  getline(std::cin, str);

  std::cout << countNumbers(str, res, pos);

  return 0;
}