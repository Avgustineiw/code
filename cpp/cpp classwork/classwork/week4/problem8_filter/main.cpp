///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem: Filter Array
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function `int* filter(int* arr, int size, int& newSize, bool (*filterFunc)(int))`
/// that filters an array based on a predicate function and returns a new array.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
bool filterFunc(int x)
{
  return x > 0;
}


int* filter(int* arr, int size, int& newSize, bool (*filterFunc)(int))
{
  int* arr_new = new int[size];
  int j = 0;

  for (int i = 0; i < size; i++) {
    if (filterFunc(arr[i])) {
      newSize++;
      arr_new[j] = arr[i];
      j++;
    } 
  }

  return arr_new;
}


void printArray(int *arr, int size)
{
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  
}

int main()
{
  int n;
  int new_size = 0;
  int* p;

  std::cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  
  p = filter(arr, n, new_size, filterFunc);
  printArray(p, new_size);
  
  return 0;
}
