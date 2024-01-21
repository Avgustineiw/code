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

bool watermelon(u16 weight)
{
  if ((weight % 2 == 0) and (weight != 2)) {
    return true;
  }   
  else {
    return false;
  }
}

int main()
{
    u16 weight;
    std::cin >> weight;
    if (watermelon(weight)) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }
    return 0;
}