#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

void averageScore(int n);

class Student
{
private:
  std::string name_;
  std::string surname_;
  int maths_;
  int physics_;
  int informatics_;
  int average_;

public:
  Student(std::string name = "name", std::string surname = "surname", 
          int maths = 0, int physics = 0, int informatics = 0)
          {
            name_ = name;
            surname_ = surname;
            maths_ = maths;
            physics_ = physics;
            informatics_ = informatics;
            average_ = maths + physics + informatics;  
          }
  
  int GetAverage() {
    return average_;
  }

  std::string GetName() {
    return name_;
  }

  std::string GetSurname() {
    return surname_;
  }
};

bool cmp(Student A, Student B)
{
  return A.GetAverage() > B.GetAverage();
}

void averageScore(int n)
{
  std::vector<Student> students;
  std::string tmp_name, tmp_surname;
  int tmp_maths, tmp_phys, tmp_inf;

  for (size_t i = 0; i < n; i++) {
    std::cin >> tmp_name;
    std::cin >> tmp_surname;
    std::cin >> tmp_maths;
    std::cin >> tmp_phys;
    std::cin >> tmp_inf;

    Student student{tmp_name, tmp_surname, tmp_maths, tmp_phys, tmp_inf};

    students.push_back(student);
  }

  stable_sort(students.begin(), students.end(), cmp);

  for (size_t i = 0; i < n; i++) {
      std::cout << students[i].GetName() << " " << students[i].GetSurname() << '\n';
    }
}

int main() 
{
  int n;
  std::cin >> n;

  averageScore(n);
  
  return 0;
}