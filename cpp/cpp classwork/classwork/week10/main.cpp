#include <cmath>
#include <cstdlib>
#include <iostream>
#include <istream>
#include <ostream>
#include <set>
class Vector3D
{
private:
  double x_;
  double y_;
  double z_;

public:
  Vector3D(double x = 0.0, double y = 0.0, double z = 0.0) {
    x_ = x;
    y_ = y;
    z_ = z;
  }

  double getX() const {
    return x_;
  }
  double getY() const {
    return y_;
  }
  double getZ() const {
    return z_;
  }

  void setX(double x) {
    x_ = x;
  }
  void setY(double y) {
    y_ = y;
  }
  void setZ(double z) {
    z_ = z;
  }

  Vector3D(const Vector3D& v2) {
    x_ = v2.getX();
    y_ = v2.getY();
    z_ = v2.getZ();
  }

  double magnitude() const {
    return sqrt(pow(x_, 2) + pow(y_, 2) + pow(z_, 2));
  }
};


Vector3D operator+(const Vector3D& v1, const Vector3D& v2)
{
  Vector3D v3;
  v3.setX(v1.getX() + v2.getX());
  v3.setY(v1.getY() + v2.getY());
  v3.setZ(v1.getZ() + v2.getZ());
  return v3;
}


double operator*(const Vector3D& v1, const Vector3D& v2)
{
  return v1.getX() * v2.getX() + v1.getY() * v2.getY() + v1.getZ() * v1.getZ();
}


Vector3D operator*(const Vector3D& v1, double d)
{
  Vector3D v2;
  v2.setX(v1.getX() * d);
  v2.setY(v1.getY() * d);
  v2.setZ(v1.getZ() * d);
  return v2;
}

bool operator<(const Vector3D& v1, const Vector3D& v2)
{
  return v1.magnitude() < v2.magnitude();
}

std::ostream& operator<<(std::ostream& out, const Vector3D& v)
{
  out << v.getX() << " " << v.getY() << " " << v.getZ() << '\n';
  return out;
}

std::istream& operator>>(std::istream& is, Vector3D& v)
{
  double x, y, z;
  is >> x >> y >> z;
  v.setX(x);
  v.setY(y);
  v.setZ(z);
  return is;
}

int main()
{
  std::multiset<Vector3D> data;
  double average = 0;
  double x, y, z;
  srand(time(NULL));

  for (size_t i = 0; i < 100; i++) {
    double tmp = RAND_MAX / 2;
    x = (rand() - tmp) / tmp;
    y = (rand() - tmp) / tmp;
    z = (rand() - tmp) / tmp;
    Vector3D v = {x, y, z};
    average += v.magnitude();
    data.insert(v);
  }

  for (auto it = data.begin(); it != data.end(); it++) {
    std::cout << *it;
  }

  std::cout << average/data.size();

  return 0;
}
