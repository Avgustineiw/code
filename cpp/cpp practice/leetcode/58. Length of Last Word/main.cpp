#include <iostream>
#include <sstream>
#include <string>
int lengthOfLastWord(std::string s)
{
  int res = 0;
  std::string tmp = "";
  std::stringstream ss(s);

  while (ss >> tmp) {
    res = tmp.size();
    // std::cout << tmp << '\n';
  }

  return res;
}


int main()
{
  std::string s = "   fly me   to   the moon  ";

  std::cout << lengthOfLastWord(s);

  return 0;
}
