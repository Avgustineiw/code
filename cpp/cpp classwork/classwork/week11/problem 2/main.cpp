#include <iostream>
#include <string>

class User 
{
 protected:
  std::string name;

 public:
  User(std::string name) : name(name) {}
  virtual void accessResources() const {
    std::cout << name << " has basic user access." << '\n';
  }
  virtual ~User() {}
};


class Employee : public User
{
public:
  Employee(std::string name) : User(name) {};
  virtual void accessResources() const {
    std::cout << name << " has staff level access" << '\n';
  }

  virtual ~Employee() {};
};


class Manager : public User
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
  Administrator(std::string name) : Employee("77"), Manager("66") {};
  virtual void accessResources() const {
    std::cout << Employee::name << " has administrator level access" << '\n';
    std::cout << Manager::name << " has administrator level access" << '\n';

  }

  virtual ~Administrator();
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
