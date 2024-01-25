#include <iostream>
#include <stdlib.h>

int main()
{
  int a;
  int i;

  std::cin >> a >> i;

  std::cout << (a | (1 << i));

  return 0;
}