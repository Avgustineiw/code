#include <iostream>
#include <vector>
#include <set>

int main()
{
  int n;
  std::set<int> data;

  while (std::cin >> n) {
    if (data.find(n) != data.end()) {
      std::cout << "YES" << '\n';
    }
    else {
      data.insert(n);
      std::cout << "NO" << '\n';
    }
  }

  return 0;
}