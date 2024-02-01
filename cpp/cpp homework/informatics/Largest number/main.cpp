#include <iostream>
#include <stdlib.h>
#include <string>

int largestNumber(std::string str, int &res, int &pos)
{
  if (pos > str.length()) {
    return res;
  }
  else if (str[pos]-'0' > res) {
    res = str[pos]-'0';
    pos++;
    return largestNumber(str, res, pos);
  }
  else {
    pos++;
    return largestNumber(str, res, pos);
  }
}

int main()
{
  std::string str;
  int res = 0, pos = 0;

  getline(std::cin, str);

  std::cout << largestNumber(str, res, pos);

  return 0;
}