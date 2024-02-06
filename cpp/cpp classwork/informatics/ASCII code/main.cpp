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
  s16 n;
  
  std::cin >> n;
  std::cout << char(n);

  return 0;
}