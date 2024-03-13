#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

struct Point
{
  int x_;
  int y_;
  double dist_;

  Point(int x = 0, int y = 0) {
    x_ = x;
    y_ = y;
    dist_ = sqrt(pow(x, 2) + pow(y, 2));
  }

  double Dist() {
    return dist_;
  }
};

bool cmp(Point A, Point B)
{
  return A.Dist() < B.Dist();
}

int main()
{
  unsigned int n;
  int tmp_x, tmp_y;
  std::string buffer, tmp;
  std::vector<Point> points;

  std::cin >> n;

  for (size_t i = 0; i < n; i++) {
    std::cin >> tmp_x >> tmp_y;
    
    Point vec{tmp_x, tmp_y};
    points.push_back(vec);
  }

  sort(points.begin(), points.end(), cmp);

  for (size_t i = 0; i < n; i++) {
    std::cout << points[i].x_ << " " << points[i].y_ << '\n';
  }

  return 0;
}