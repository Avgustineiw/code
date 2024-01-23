#include <iostream>
#include <stdlib.h>
#include <string>

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
  s32 n, x = 0;
  std::string temp;

  std::cin >> n;

  for (u32 i = 0; i < n; i++)
  {
    std::cin >> temp;
    
    if ((temp == "X++") || (temp == "++X")) {
      x += 1;
    }
    else {
      x -= 1;
    }
  }

  std::cout << x;
  
  return 0;
}