#include <iostream>
#include <stdlib.h>

typedef long  s64;
typedef int   s32;
typedef short s16;
typedef char  s8;
typedef unsigned long  u64;
typedef unsigned int   u32;
typedef unsigned short u16;
typedef unsigned char  u8;

int main()
{
  u8 value_1, value_2;

  std::cin >> value_1 >> value_2; 

  for (u16 i = int(value_1); i <= int(value_2); i++)
  {
    std::cout << char(i);
  }

  return 0;
}