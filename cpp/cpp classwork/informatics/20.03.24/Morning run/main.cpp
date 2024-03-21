#include <iomanip>
#include <iostream>
int main()
{
  double x, y;
  int day {1};
  std::cin >> std::setprecision(6);
  std::cin >> x >> y;

  while (x < y) {
    x *= 1.7;
    day++;
  }

  // std::cout << x << " "<< y << '\n';
  std::cout << day;
}
