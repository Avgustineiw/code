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
  u16 n;
  std::cin >> n;
  std::string arr[100];

  for (u16 i = 0; i < n; i++)
  {
    std::cin >> arr[i];
  }  

  for (u16 i = 0; i < n; i++) {
    if (arr[i].length() > 10) {
      std::cout << arr[i][0] << arr[i].length()-2 << arr[i].back() << std::endl;
    }
    else {
      std::cout << arr[i] << std::endl;
    }
  }
}    