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
  double av_maths = 0, av_physics = 0, av_informatics = 0;

  for (int i = 0; i < n; i++) {
    std::cin >> students[i].name;
    std::cin >> students[i].surname;
    std::cin >> students[i].maths;
    std::cin >> students[i].physics;
    std::cin >> students[i].informatics;
  }
  
  for (int i = 0; i < n; i++) {
    av_maths += students[i].maths;
    av_physics += students[i].physics;
    av_informatics += students[i].informatics;
  }

  av_maths /= n;
  av_physics /= n;
  av_informatics /= n;

  std::cout << av_maths << " " << av_physics << " " << av_informatics << '\n';
}


int main() 
{
  int n;
  std::cin >> n;

  averageScore(n);
  
  return 0;
}