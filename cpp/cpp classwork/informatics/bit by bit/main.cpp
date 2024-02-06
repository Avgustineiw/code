#include <iostream>
#include <stdlib.h>

int main()
{
  int n;
  int res = 0;
  int val;

  std::cin >> n;

  for (int i = 7; i > -1; i--)
  {
    val = (1 << i);
    if (((n & val) >> i) == 1) {
      std::cout << 1;
    }
    else {
      std::cout << 0;
    }
  }
  return 0;
}