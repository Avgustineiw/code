#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>

std::string soundex(std::string str)
{
  for (int i = 1; i < str.length(); i++) {
    switch (str[i]) {
      case 'a':
      case 'e':
      case 'h':
      case 'i':
      case 'o':
      case 'u':
      case 'w':
      case 'y':
        str.erase(i, 1);
        i--;
        break;
    }
  }

  for (int i = 1; i < str.length(); i++) {
    switch (str[i]) {
      case 'b':
      case 'f':
      case 'p':
      case 'v':
        str.replace(i, 1, "1");
        break;

      case 'c':
      case 'g':
      case 'j':
      case 'k':
      case 'q':
      case 's':
      case 'x':
      case 'z':
        str.replace(i, 1, "2");
        break;
      
      case 'd':
      case 't':
        str.replace(i, 1, "3");
        break;

      case 'l':
        str.replace(i, 1, "4");
        break;

      case 'm':
      case 'n':
        str.replace(i, 1, "5");
        break;

      case 'r':
        str.replace(i, 1, "6");
        break;
    }
  }

  for (int i = 0; i < str.length(); i++)
  {
    if (isdigit(str[i])) {
      if (str[i] == str[i+1]) {
        str.erase(i, 1);
        i--;
      }
    }
  }
  
  if (str.length() > 4) {
    str.erase(str.begin()+4, str.end());
  }
  else {
    while (str.length() < 4) {
      str.append("0");
    }
  }
  return str;
}

int main()
{
  std::string str;

  getline(std::cin, str);

  std::cout << soundex(str);

  return 0;
}