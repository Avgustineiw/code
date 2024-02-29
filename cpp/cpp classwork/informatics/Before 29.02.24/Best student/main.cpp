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

student students[1000];
std::vector<int> total_average;

void averageScore(int n)
{
  std::string line, word;
  double av_maths = 0, av_physics = 0, av_informatics = 0, average = 0;

  for (int i = 0; i < n; i++) {
    std::cin >> students[i].name;
    std::cin >> students[i].surname;
    std::cin >> students[i].maths;
    std::cin >> students[i].physics;
    std::cin >> students[i].informatics;
    students[i].average = students[i].maths + students[i].physics + students[i].informatics;
    total_average.push_back(students[i].average);
  }

  average = *std::max_element(std::begin(total_average), std::end(total_average));

  for (int i = 0; i < n; i++) {
    if (students[i].average == average) {
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