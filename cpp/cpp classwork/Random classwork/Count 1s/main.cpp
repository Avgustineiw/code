#include <iostream>
#include <stdlib.h>

int main()
{
  int n;
  int res = 0;
  int val;

  std::cin >> n;

  for (int i = 0; i < 32; i++)
  {
    val = (1 << i);
    if (((n & val) >> i) == 1) {
      res++;
    }
  }
  std::cout << res;
  return 0;
}