///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Sum digits
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that takes a number and
/// find sum of digits recursively.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

int digit_sum(int value)
{
  if (value == 0) {
    return 0;
  }
  return (value % 10 + digit_sum(value / 10));
}

int main()
{
    int n;

    std::cin >> n;

    std::cout << digit_sum(n);

    return 0;
}
