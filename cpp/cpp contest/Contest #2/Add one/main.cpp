#include <iostream>
#include <stdlib.h>
#include <string>

std::string increment(std::string str)
{
  int var;
  int i = str.length() - 1;

  while (i >= 0) {
    if (str[i] - '0' != 9) {
      var = (str[i] - '0') + 1;
      std::string s = std::to_string(var);
      str.replace(i, 1, s);
      break;
    }
    else {
      str.replace(i, 1, "0");
      if (i == 0) {
        str.insert(0, 1, '1');
      }
    }
    i--;
  }

  return str;
}

int main()
{
  std::string n;

  getline(std::cin, n);

  std::cout << increment(n);

  return 0;
}