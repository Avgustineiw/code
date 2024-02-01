///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem: Increment Value
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function `void increment(int &value)` 
/// that increments the value of 
/// the passed integer by 1.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

void incremenet(int &value)
{
  value++;

  return;
}

int main()
{
  int n, res = 0;

  std::cin >> n;

  incremenet(n);

  std::cout << n;
  
  return 0;
}
