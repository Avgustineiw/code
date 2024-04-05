#include <cctype>
#include <iostream>
#include <string>
std::string makeGood(std::string s) {   
  while (true) {
    std::string tmp = s;
    for (size_t i = 1; i < s.size(); i++) {
      if (s[i] - 'A' == s[i - 1] - 'a' || s[i] - 'a' == s[i - 1] - 'A')
            s.erase(i - 1, 2);
    }

    if (s == tmp) 
      break;
  }

  return s;

}


int main()
{
  std::string s = "abBAcC";

  makeGood(s);

  return 0;
}
