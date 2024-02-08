#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <fstream>

void permutation(int *arr, int size)
{
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (arr[j] == i + 1) {
        std::cout << j + 1 << " ";
        break;
      }
    }
  }
}


int main()
{
  int n, tmp;
  std::cin >> n;
  int arr[n];

  for (int i = 0; i < n; i++) {
    std::cin >> tmp;
    arr[i] = tmp;
  }

  permutation(arr, n);

  return 0;
}