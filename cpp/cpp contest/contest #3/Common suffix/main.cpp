#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <fstream>

std::string common_suffix(const std::string& a, const std::string& b) {
  std::string suf;
  int size_a = a.length()-1, size_b = b.length()-1;

  while (size_a >= 0 && size_b >= 0 && a[size_a] == b[size_b]) {
    suf += a[size_a];
    size_a--;
    size_b--;
  }
  reverse(suf.begin(), suf.end());

  return suf;
}

int main()
{
  std::string str_1, str_2;

  std::cin >> str_1 >> str_2;

  std::cout << common_suffix(str_1, str_2);

  return 0;
}