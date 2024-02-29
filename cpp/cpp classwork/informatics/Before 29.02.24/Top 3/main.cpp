#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

void averageScore(int n);

struct student
{
  std::string name;
  std::string surname;
  int maths;
  int physics;
  int informatics;
  int average;
};

student students[100001];
std::vector<int> grades;

void averageScore(int n)
{
  std::string line, word;
  int av_maths = 0, av_physics = 0, av_informatics = 0, max1 = 0, max2 = 0, max3 = 0;

  for (int i = 0; i < n; i++) {
    std::cin >> students[i].name;
    std::cin >> students[i].surname;
    std::cin >> students[i].maths;
    std::cin >> students[i].physics;
    std::cin >> students[i].informatics;
    students[i].average = students[i].maths + students[i].physics + students[i].informatics;
    grades.push_back(students[i].average);
  }

  for (int i = 0; i < n; i++) {
    if (grades[i] > max1) {
      max3 = max2;
      max2 = max1;
      max1 = grades[i];
    }
    else if (grades[i] > max2) {
      max3 = max2;
      max2 = grades[i];
    }
    else if (grades[i] > max3) {
      max3 = grades[i];
    }
  }
  
  for (int i = 0; i < n; i++) {
    if (students[i].average == max1 || students[i].average == max2 || students[i].average == max3) {
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