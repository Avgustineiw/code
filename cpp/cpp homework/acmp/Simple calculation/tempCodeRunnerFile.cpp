#include <iostream>
#include <stdlib.h>
#include <string>

unsigned long long int FromDecimal(int num, int system)
{
  unsigned long long int res = 0;

  while (num > 0) {
    res += num / system;
    num /= system;
  }
  
  return res;
}


int main()
{
  int n, k;

  std::cin >> n >> k;

  std::cout << FromDecimal(n, k);
  return 0;
}