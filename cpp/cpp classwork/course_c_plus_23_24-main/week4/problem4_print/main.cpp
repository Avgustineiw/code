///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem: Print Data
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write overloaded functions `void print(int)` and `void print(double)` that
/// print an integer and a double, respectively.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

void print(int value)
{
  std::cout << value << std::endl;
}

void print(double value)
{
  std::cout << value << std::endl;
}

int main()
{
    // Your code here
  double n_1;
  int n_2;

  std::cin >> n_1 >> n_2;

  print(n_1);
  print(n_2);

  return 0;
}
