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

bool isDigit(s32 val)
{
  if (int(val) >= '0' && int(val) <= '9') {
    return true;
  }
  else {
    return false;
  }
}

int main()
{
  s8 n;

  std::cin >> n;
  
  if (isDigit(n)) {
    std::cout << "YES";
  }
  else {
    std::cout << "NO";
  }

  return 0;
}