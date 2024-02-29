#include <iostream>
#include <set>

int main()
{
  std::set <int> data;
  int c;

  while (std::cin >> c) {
    data.insert(c);
  }
  
  std::cout << data.size();

  return 0;
}