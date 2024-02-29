#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

void averageScore(int n);

struct student
{
  std::string name;
  std::string surname;
  int maths;
  int physics;
  int informatics;
};

student students[100];

void averageScore(int n)
{
  std::string line, word;

  for (int i = 0; i < n; i++) {
    std::cin >> students[i].name;
    std::cin >> students[i].surname;
    std::cin >> students[i].maths;
    std::cin >> students[i].physics;
    std::cin >> students[i].informatics;
  }
  
  for (int i = 0; i < n; i++) {
    if (students[i].maths > 3 && students[i].physics > 3 && students[i].informatics > 3) {
      std::cout << students[i].name << " " << students[i].surname << '\n';
    }
  }
}


int main() 
{
  int n;
  std::cin >> n;

  averageScore(n);
  
  return 0;
}