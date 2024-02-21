#include <iostream>
#include <stdlib.h>

int main()
{
  int a, i;

  std::cin >> a >> i;
  
  int var = 1 << i;

  std::cout << (a ^ (1 << i));

  return 0;
}