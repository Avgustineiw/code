#include <iostream>
#include <string>
#include <vector>

void print(std::vector<int>& arr, int size);
void input(std::vector<int>& arr, int size);

void input(std::vector<int>& arr, int size)
{
  for (int i = 0; i < size; i++) {
    std::cin >> arr[i];
  }
}


void print(std::vector<int>& arr, int size)
{
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
}


int main() {
  int size, len, num;
  std::cin >> size;
  std::vector<int> arr(size, 0), res(size, 0);
  std::vector<bool> stor(size, true);

  input(arr, size);

// [0, 0, 2]
// [0, 0, 0]
//  ^  ^  ^
//  1  2  3

// [2, 3, 1]


  for (int i = size-1; i >= 0; i--) {
    len  = size - 1;
    num = 0;

    while (num < arr[i] || !stor[len]) {
      if (stor[len]) num++;
      len--;
    }
    res[i] = len + 1;
    stor[len] = false;
  }
  
  print(res, size);

  return 0;
}