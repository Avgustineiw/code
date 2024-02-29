#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <fstream>

int Fib(int n)
{
  if (n <= 1) {
    return n;
  }
  return Fib(n - 1) + Fib(n - 2);
}


int main()
{
  int n;

  std::cin >> n;

  std::cout << Fib(n);

  return 0;
}