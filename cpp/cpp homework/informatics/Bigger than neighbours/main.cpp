#include <iostream>
#include <stdlib.h>
#include <string>

int arr[10000];

int main()
{
  size_t i = 0, res = 0;

  while (std::cin >> *(arr + i)) {
    i++;
  }
  
  for (int j = 1; j < i - 1; j++)
  {
    if (*(arr + j) > *(arr + j - 1) && *(arr + j) > *(arr + j + 1)) {
      res++;
    }
  }

  std::cout << res;

  return 0;
}