///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem: Array Transformation
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function `void transformArray(int* arr, int size, int (*transform)(int))`
/// that applies a transformation function to each element of an array.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

int f(int x)
{
  return x * 2;
}

void transformArray(int* arr, int size, int (*transform)(int))
{
  for (int i = 0; i < size; i++) {
    arr[i] = f(arr[i]);
  }
  
}

int main()
{
  int n;

  std::cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  
  transformArray(arr, n, f);

  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  
  return 0;
}
