
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>
class Point 
{
private:
  int x_;
  int y_;

public: 
  Point(int x = 0, int y = 0) {
    x_ = x;
    y_ = y;
  }

  int getX() const {
    return x_;
  }
  int getY() const {
    return y_;
  }

  void setX(int x) {
    x_ = x;
  }
  void setY(int y) {
    y_ = y;
  }
};

double area(Point A, Point B, Point C)
{
  int x1 = A.getX();
  int x2 = B.getX();
  int x3 = C.getX();
  int y1 = A.getY();
  int y2 = B.getY();
  int y3 = C.getY();

  double res = abs((x2-x1)*(y3-y1) - (x3-x1)*(y2-y1));
  return res/2;
}

int main()
{
  int n;
  std::cin >> n;
  std::vector<Point> data;
  double res = 0;

  for (size_t i = 0; i < n; i++) {
    int x, y;
    std::cin  >> x >> y;
    Point p = {x, y};
    data.push_back(p);
  }

  for (size_t i = 0; i < data.size() - 2; i++) {
    for (size_t j = i + 1; j < data.size() - 1; j++) {
      for (size_t k = j + 1; k < data.size(); k++) {
        double a = area(data[i], data[j], data[k]);
        res = std::max(res, a);
      }
    }
  }
  
  std::cout << std::setprecision(15);
  std::cout << res;

  return 0;
}
