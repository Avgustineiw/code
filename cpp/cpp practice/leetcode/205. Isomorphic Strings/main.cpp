#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
bool isIsomorphic(std::string s, std::string t)
{
  std::unordered_map<char, char> data_s, data_t;

  for (size_t i = 0; i < s.size(); i++) {
    if (data_s.count(s[i]) == 0 && data_t.count(t[i]) == 0) {
      data_s[s[i]] = t[i];
      data_t[t[i]] = s[i];
    }
    else {
      if (data_s[s[i]] != t[i] || data_t[t[i]] != s[i]) 
        return false;
    }
  }

  return true;
}


int main()
{
  std::string s = "bbbaaaba";
  std::string t = "aaabbbba";

  std::cout << isIsomorphic(s, t);

  return 0;
}

