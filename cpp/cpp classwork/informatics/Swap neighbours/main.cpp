#include <iostream>
#include <stdlib.h>
#include <string>

int arr[10000];

int main()
{
  int i = 0;

  while (std::cin >> *(arr + i)) {
    i++;
  }

  for (int j = 0; j < (i/2)*2; j += 2) {
    std::cout << *(arr + j + 1) << " " << *(arr + j) << " ";     
  }

  if ((i/2)*2 < i) {
    std::cout << *(arr + i - 1);
  }

  return 0;
}