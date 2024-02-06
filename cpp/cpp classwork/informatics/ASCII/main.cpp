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
  for (s16 i = 33; i < 127; i++)
  {
    std::cout << char(i) << " " << i << std::endl;
  }
  
  return 0;
}