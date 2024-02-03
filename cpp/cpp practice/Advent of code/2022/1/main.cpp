#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <fstream>

int main()
{
  std::ifstream file("input.txt");
  std::string str;
  int temp = 0, res = 0, temp_res = 0;

  if (file.is_open()) {
    while (!file.eof()) {
      getline(file, str);
      if (!str.empty()) {
        temp = stoi(str);
        temp_res += temp;
      }
      else {
        if (temp_res > res) {
          res = temp_res;
        }
        temp_res = 0;
      }
    }
  }
  
  std::cout << res;

  return 0;
}