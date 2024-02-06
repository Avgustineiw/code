#include <iostream>
#include <stdlib.h>
#include <string>

int main()
{
  int n, k, sum = 0, product = 1, res = 0;

  std::cin >> n >> k;

  while (n > 0) {
    sum += n % k;
    product *= n % k;
    n /= k;
  }
  res = product - sum;

  std::cout << res;
  
  return 0;
}