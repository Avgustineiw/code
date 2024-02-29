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
  
  for (int j = 0; j < i; j++) {
    if (j == 0) {
      std::cout << *(arr + i - 1) << " ";
    }
    else {
      std::cout << *(arr + j - 1) << " ";
    }
  }
  
  return 0;
}