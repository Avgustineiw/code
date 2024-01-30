#include <iostream>
#include <stdlib.h>
#include <string>

int a[10];

int main()
{
  int *p = a;

  for (int i = 0; i < 10; i++) {
    std::cout << i+1 << ": " << p << std::endl;
    p++;
  }
  

  return 0;
}