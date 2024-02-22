///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       14.02.2024
///
/// TASK DESCRIPTION
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
/*
Car
Define a Car struct with private attributes
for year of manufacture (year), color (color),
number of doors (count_doors), fuel level
(fuel_level) and mileage (mileage).
Implement a constructor to initialize these
attributes. Fuel level and mileage must be
the default values are 50.0 and 0.0 respectively.
Implement the drive(double distance) method.
which reduces the fuel level depending on
distance traveled and increases mileage.
  Assume that the car consumes 1 liter
  fuel for 10 km.
Implement the refuel(double amount) method to
  add fuel to the tank.
Add a stop() method that prints a message
that the car has been stopped.
Implement an info() method that prints information
about the car: year of manufacture, color, number of doors,
fuel level and mileage.
Implement methods to change colors
car and obtaining current color values,
fuel level and mileage.
In the main function, create several Car objects with different characteristics.
Test all class methods to make sure they work correctly. Try walking some distance, refueling the car, changing its color and then displaying information about it.
*/

struct Car 
{
  int year;
  std::string col;
  int count_doors;
  double fuel_level;
  int mileage;


  Car(int y, std::string c, int d, double f = 50.0, double dis = 0.0) {
      year = y;
      col = c;
      count_doors = d;
      fuel_level = f;
      mileage = dis;
  }


  void drive(double distance) {
    if (fuel_level - distance > 0) { 
      fuel_level -= distance/10;
      mileage += distance;
    }
    else 
      std::cout << "Not enough fuel" << "\n\n";
  }


  void refuel(double amount) {
    if (fuel_level + amount > 50) {
      std::cout << (fuel_level + amount) - 50 << " litres of excess fuel" << "\n\n";
      fuel_level = 50;
    }
    else 
      fuel_level += amount;
  }


  void stop() {
    std::cout << "Car has been stopped" << "\n\n";
  }


  void color() {
    std::cout << "To get the current color type: 1" << '\n' << "To change the color type: 2" << '\n';

    int tmp; 
    std::cin >> tmp;
    std::cout << '\n';

    switch (tmp) {
      case 1:
        std::cout << col << "\n\n";
        break;
      case 2:
        std::cout << "Type the new color" << '\n';
        std::cin >> col;
        std::cout << '\n';
        break;
      default:
        std::cout << "No interaction for this input" << "\n\n";
        break; 
    }
  }

  void info() {
      std::cout << "Year: " << year << '\n'
      << "Color: " << col << '\n'
      << "Doors: " << count_doors << '\n'
      << "Fuel " << fuel_level << '\n'
      << "Mileage: " << mileage << "\n\n";
  }
};

int main() 
{
  Car car1(2010, "black", 5);
  car1.info();
  car1.drive(35);
  car1.refuel(20);
  car1.stop();
  car1.color();
  car1.info();
  Car car2(2022, "white", 3);

  return 0;
}