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
  u16 n;
  u16 res;
  u16 temp_in;
  int temp_res[3];
  
  res = 0;
  std::cin >> n;

  for (u16 i = 0; i < n; i++)
  {
    // std::fill_n(temp_res, 3, 0);

    for (u16 j = 0; j < 3; j++)
    {
      temp_in = 0;
      std::cin >> temp_in;
      temp_res[i] = temp_in;
    }
    std::cout << temp_res[0] << " " << temp_res[1] << " " << temp_res[2];
  }
}