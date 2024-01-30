#include <iostream>
#include <stdlib.h>
#include <string>

int arr[10000];

int main()
{
  int i = 0;

  while (std::cin >> *(arr + i)) {
    if (i % 2 == 0) {
      std::cout << *(arr + i) << " ";
    }
    i++;
  }

  return 0;
}