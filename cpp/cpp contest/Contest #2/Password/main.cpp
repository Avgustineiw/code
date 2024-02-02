#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>

bool len(std::string str)
{
  if (str.length() > 7 && str.length() < 15) {
    //std::cout << "len check true" << std::endl;
    return true;
  }
  //std::cout << "len check false" << std::endl;
  return false;
}

bool ascii(std::string str)
{
  for (int i = 0; i < str.length(); i++)
  {
    if (!(int(str[i]) > 32 && int(str[i]) < 128)) {
      //std::cout << "ascii check false" << std::endl;
      return false;
    }
  }
  //std::cout << "ascii check true" << std::endl;
  return true;
}

int symbols(std::string str)
{
  int flag_large = 0, flag_small = 0, flag_num = 0, flag_other = 0, res = 0;

  for (int i = 0; i < str.length(); i++) {
    if (int(str[i]) > 64 && int(str[i]) < 91) {
      flag_large = 1;
    }
    else if (int(str[i]) > 96 && int(str[i]) < 123) {
      flag_small = 1;
    }
    else if (int(str[i]) > 47 && int(str[i] < 58)) {
      flag_num = 1;
    }
    else {
      flag_other = 1;
    }
  }
  res = (flag_large + flag_small + flag_num + flag_other);

  return res;
}

bool validPassword(std::string str)
{
  if (ascii(str) && (symbols(str) > 2) && len(str)) {
    return true;
  }

  return false;
}

int main()
{
  std::string str;

  getline(std::cin, str);

  if (validPassword(str)) {
    std::cout << "YES";
  }
  else {
    std::cout << "NO";
  }

  return 0;
}