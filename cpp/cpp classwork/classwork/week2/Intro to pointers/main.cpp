#include <iostream>
#include <stdlib.h>
#include <string>

int main()
{
  int x = 35, y = 15, temp = x;  

  int* t_1 = &x;
  int* t_2 = &y;

  *t_1 = y;
  *t_2 = temp;

  std::cout << x << " " << y;

  return 0;
}