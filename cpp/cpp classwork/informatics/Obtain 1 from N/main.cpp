#include <iostream>
#include <stdlib.h>
#include <string>

bool fromN(int value) 
{
  if (value == 1) {
    return true;
  }
  else if (value <= 0) {
    return false;
  }
  else {
    return (fromN(value - 3) || fromN(value - 5));
  }
}

int main()
{
  int n;

  std::cin >> n;

  if (fromN(n)) {
    std::cout << "YES";
  }
  else {
    std::cout << "NO";
  }

  return 0;
}