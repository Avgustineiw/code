#include <iostream>
#include <stdlib.h>
#include <string>

double circle_area(double radius, double &perimeter)
{
  double s;

  perimeter = 2 * acos(-1) * radius;
  s = (radius * radius) * acos(-1);

  return s;
}

int main()
{
  double r, p = 0;

  std::cin >> r;

  std::cout << circle_area(r, p) << " " << p;

  return 0;
}