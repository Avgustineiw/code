#include <iostream>
#include <iterator>
#include <string>
// User class: The base class from which the
// all other classes are inherited. Includes
// basic information about the user (for example, name).

// Employee class: Derived from User, representing
// employee. Adds a level of access to resources specific
// for staff.

// Manager class: Derived from User, representing a manager.
// Managers have a higher level of access than regular ones
// employees, and can manage department resources.

// Administrator class: Derived class that should inherit
// properties and methods from both Employee and Manager. Administrators
// have the highest level of access allowing them to manage resources
// at all levels.

// Implement a class system using virtual inheritance,
// to solve the problem of diamond-shaped inheritance and correctly
// organize a hierarchy of classes User, Employee, Manager and
//Administrator. Every class must provide a method
// accessResources() demonstrating the user's access level.

class User {
 protected:
  std::string name;

 public:
  User(std::string name) : name(name) {}
  virtual void accessResources() const {
    std::cout << name << " has basic user access." << '\n';
  }
  virtual ~User() {}
};


class Employee : virtual public User
{
public:
  Employee(std::string name) : User(name) {};
  virtual void accessResources() const {
    std::cout << name << " has staff level access." << '\n';
  }

  virtual ~Employee() {};
};


class Manager : virtual public User
{
public:
  Manager(std::string name) : User(name) {};
  virtual void accessResources() const {
    std::cout << name << " has manager level access" << '\n';
  }

  virtual ~Manager() {};
};


class Administrator : public Employee, public Manager
{
public:
  Administrator(std::string name) : Employee("77"), Manager("88"), User(name) {};
  virtual void accessResources() const {
    std::cout << name << " has has administrator level access" << '\n';
  }
};

int main()
{
  Employee Tom = {"Tom"};
  Tom.accessResources();
  Manager Paul = {"Paul"};
  Paul.accessResources();
  Administrator Bob = {"Bob"};
  Bob.accessResources();

  return 0;
}
