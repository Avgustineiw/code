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
  char str[4] = "abc";
  std::string str_1 = "edf";
  std::string s;

  s = str + str_1;

  std::cout << s;

  return 0;
}