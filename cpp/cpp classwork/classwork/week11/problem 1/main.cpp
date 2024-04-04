#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <vector>

// Implement a class system to represent various
// geometric shapes and calculation of their area.

// Base class Shape:
// Contains the x and y coordinates of the shape's center.
// Declares the area() function to calculate area.
// Derived class Circle:
// Inherits Shape.
// Adds the radius property.
// Implements the area() function to calculate the area of a circle.
// Rectangle derived class:
// Inherits Shape.
// Adds width and height properties.
// Implements the area() function to calculate the area of a rectangle.

class Shape 
{
protected:
  double x, y;

public:
  Shape(double x, double y) : x(x), y(y) {};
  virtual double area() const = 0;
  virtual ~Shape() {}
};


class Circle : public Shape
{
protected:
  double r;

public:
  Circle(double x, double y, double r) : Shape(x, y) {
    this->r = r;
  }

  virtual double area() const {
    return std::pow(r, 2) * cos(-1);
  }

  virtual ~Circle() {};
};


class Rectangle : public Shape
{
protected:
  double width;
  double height;

public:
  Rectangle(double x, double y, double width, double heigth) : Shape(x, y) {
    this->width = width;
    this->height = heigth;
  }
  
  virtual double area() const {
    return this->height * this->width;
  }

  virtual ~Rectangle() {};
};

int main() 
{
  std::vector<Shape*> data;
  Circle cir = {2, 2, 3};
  Rectangle rec = {1, 1, 3, 4};

  data.push_back(&cir);
  data.push_back(&rec);

  for (size_t i = 0; i < data.size(); i++) {
    std::cout << data[i]->area() << '\n';
  }

  return 0;
}
