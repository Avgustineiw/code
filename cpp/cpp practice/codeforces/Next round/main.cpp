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
  u16 n, k, temp, res = 0;
  int arr[100];

  std::cin >> n >> k;

  for (u32 i = 0; i < n; i++)
  { 
    std::cin >> temp;
    arr[i] = temp;
  }

  for (u32 j = 0; j < n; j++)
  {
    if ((arr[j] > 0) and (arr[j] >= arr[k-1])) {
      res += 1;
    }
  }
  std::cout << res;

  return 0;
}