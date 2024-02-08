#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <fstream>

void generator(int n, int k)
{
  for (int i = 1; i < k + 1; i++) {
    for (int j = 1; j < k + 1; j++) {
      std::cout << j << " " << i << std::endl;
    }
  }
}


int main()
{
  int n, k;

  std::cin >> n >> k;

  generator(n, k);

  return 0;
}