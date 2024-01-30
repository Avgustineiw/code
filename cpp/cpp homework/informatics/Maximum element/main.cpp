#include <iostream>
#include <stdlib.h>
#include <string>

int arr[10000];

int main()
{
  int i = 0, pos = 0, maxx = 0;

  while (std::cin >> *(arr + i)) {  
    if (i == 0 || maxx < *(arr + i)) {
      maxx = *(arr + i);
      pos = i;
    }

    i++;
  }
  
  std::cout << maxx << " " << pos;

  return 0;
}