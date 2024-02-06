#include <iostream>
#include <stdlib.h>
#include <string>

int arr[35];

int main()
{
  int n, temp;

  std::cin >> n;

  int *p = arr;

  for (int i = 0; i < n; i++)
  {
    std::cin >> temp;

    *(p + i) = temp;
  }

  long long int res = *arr;

  for (int i = 0; i < n; i++)
  {
    if (*(p + i) > res) {
      res = *(p + i);
    }
  }
  
  std::cout << res;

  return 0;
}