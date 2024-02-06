#include <iostream>
#include <stdlib.h>

int main()
{
  int n;

  std::cin >> n;

  int k = 1 << n;

  std::cout << k;

  return 0;
}