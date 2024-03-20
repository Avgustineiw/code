#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
class Point 
{
private:
  int x_;
  int y_;

public: 
  Point(int x, int y) {
    x_ = x;
    y_ = y;
  }

  int getX() const {
    return x_;
  }
  int getY() const {
    return y_;

  }
};

double dist(Point A, Point B)
{
  return sqrt(pow(B.getX() - A.getX(), 2) + pow(B.getY() - A.getY(), 2)); 
}

int main()
{
  int n;
  std::cin >> n;
  std::vector<Point> data;
  double res;

  for (size_t i = 0; i < n; i++) {
    int x, y;
    std::cin  >> x >> y;
    Point p = {x, y};
    data.push_back(p);
  }

  for (size_t i = 0; i < data.size() - 2; i++) {
    for (size_t j = i + 1; j < data.size() - 1; j++) {
      for (size_t k = j + 1; k < data.size(); k++) {
        double d = dist(data[i], data[j]) + dist(data[j], data[k]) + dist(data[k], data[i]);
        if (res < d)
          res = d;
      }
    }
  }
  
  std::cout << std::setprecision(15);
  std::cout << res;

  return 0;
}
