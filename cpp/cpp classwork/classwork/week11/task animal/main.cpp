#include <iostream>
#include <string>
#include <vector>
class Animal
{
protected:
  std::string name;
  int weight;

public:
  Animal(std::string name, int weigth) : name(name), weight(weigth) {};
  virtual ~Animal() {};
  virtual void Print() {};
};

class Cat : public Animal
{
protected:
  std::string breed;

public:
  Cat(std::string name, int weigth, std::string breed) : Animal(name, weigth) {
    this->breed = breed;
  }
  virtual ~Cat() {};
  virtual void Print() {
    std::cout << "Name: " << name << '\n'; 
    std::cout << " Weigth: " << weight << " kg" << '\n';
    std::cout << " Breed: " << breed << "\n\n"; 
  }
};

class Dog : public Animal
{
protected:
  std::string breed;

public:
  Dog(std::string name, int weigth, std::string breed) : Animal(name, weigth) {
    this->breed = breed;
  }
  virtual ~Dog() {};
  virtual void Print() {
    std::cout << "Name: " << name << '\n'; 
    std::cout << " Weigth: " << weight << " kg" << '\n';
    std::cout << " Breed: " << breed << "\n\n"; 
  }
};

int main()
{
  std::vector<Animal*> data;
  Dog Bobick = {"Bobick", 100, "Golden Retriever"};
  Cat Shareeque = {"Shareeque", 150, "black"};

  data.push_back(&Bobick);
  data.push_back(&Shareeque);

  for (size_t i = 0; i < data.size(); i++) {
    data[i]->Print();
  }

  return 0;
}
