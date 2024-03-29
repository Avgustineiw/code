#include <iostream>
int main()
{
  int n, a, b, c;
  std::cin >> n;

  while (n--) {
    std::cin >> a >> b >> c;
    if (a < b && b < c) {
      std::cout << "STAIR" << '\n';
    }
    else if (a < b && b > c) {
      std::cout << "PEAK" << '\n';
    }
    else {
      std::cout << "NONE" << '\n';
    }
  }
}
