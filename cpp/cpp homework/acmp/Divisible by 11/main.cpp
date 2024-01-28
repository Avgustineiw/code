#include <iostream>
#include <stdlib.h>
#include <string>

int main()
{
  std::string n;
  int even = 0, odd = 0;

  std::cin >> n;

  for (int i = 0; i < n.length(); i++)
  {
    if (i % 2 == 0) {
      odd += (n[i] - '0');
    }
    else {
      even += (n[i] - '0');
    }
  }
  
  if ((even - odd) % 11 == 0) {
    std::cout << "YES";
  }
  else {
    std::cout << "NO";
  }

  return 0;
}