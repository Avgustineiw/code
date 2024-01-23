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
  std::string str;

  std::cin >> str;
  
  str[0] = toupper(str[0]);
  std::cout << str;
  return 0;
}