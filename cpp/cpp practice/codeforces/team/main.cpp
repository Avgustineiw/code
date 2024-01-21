#include <iostream>
#include <stdlib.h>
#include <vector>

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
  u16 n, res(0), Petya, Vasya, Tonya;

  std::cin >> n;

  for (u16 i = 0; i < n; i++) {
    std::cin >> Petya >> Vasya >> Tonya;

    if (Petya + Vasya + Tonya > 1) {
      res += 1;
    }
  }
  std::cout << res << std::endl;

  return 0;
}

