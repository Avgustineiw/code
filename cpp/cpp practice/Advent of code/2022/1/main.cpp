#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <fstream>

int main()
{
  std::ifstream file("input.txt");
  std::string str;
  int temp = 0, temp_res = 0;
  int res[3];

  if (file.is_open()) {
    while (!file.eof()) {
      getline(file, str);
      if (!str.empty()) {
        temp = stoi(str);
        temp_res += temp;
      }
      else {
        int small = INT_MAX;
        int pos = 0;

        for (int i = 0; i < 3; i++) {
          if (small > res[i]) {
            small = res[i];
            pos = i;
          }
        }

        if (temp_res > res[pos]) {
          res[pos] = temp_res;
        }

        temp_res = 0;
      }
    }
  }
  
  std::cout << res[0] + res[1] + res[2];

  return 0;
}