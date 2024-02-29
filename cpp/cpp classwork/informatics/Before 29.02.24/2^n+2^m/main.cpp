#include <iostream>
#include <stdlib.h>

int main()
{
  int n;
  int m;

  std::cin >> n >> m;

  int val_s1 = 1 << n;
  int val_2 = 1 << m;

  std::cout << (val_1 ^ val_2);

  return 0;
}