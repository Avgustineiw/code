#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

int main()
{
  unsigned int m;
  unsigned int res = 0;

  std::cin >> m;

  while (m > 0) {
    res = (res * 2) + (m % 2);
    m = m/2;
  }
  std::cout << res;

  return 0;
}