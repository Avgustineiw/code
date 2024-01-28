#include <iostream>
#include <stdlib.h>
#include <string>

unsigned long long int TernaryToDecimal(unsigned long long int num)
{
  unsigned long long int res = 0;
  
  for (int i = 0; num != 0; i++)
  {
    res += (num % 10) * pow(3, i);
    num /= 10;
  }

  return res;
}

int main()
{
  unsigned long long int n, m;
  
  std::cin >> n >> m;

  std::cout << TernaryToDecimal(n) + TernaryToDecimal(m);

  return 0;
}