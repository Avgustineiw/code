#include <iostream>
#include <stdlib.h>

int main()
{
  int a;
  int i;

  std::cin >> a >> i;

  int val = 1 << i;

  std::cout << ((a & val) >> i);

  return 0;
}