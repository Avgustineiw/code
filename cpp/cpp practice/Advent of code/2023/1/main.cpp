#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <fstream>

void calibration()
{
  std::ifstream in("input.txt");
  std::string tmp, num;
  int res = 0;

  while (!in.eof()) {
    getline(in, tmp);
    num = "";
    for (int i = 0; i < tmp.length(); i++) {
      if (int(tmp[i]) > 47 && int(tmp[i]) < 58) {
        num += tmp[i];
        break;
      }
    }

    for (int i = tmp.length(); i >= 0; i--) {
      if (int(tmp[i]) > 47 && int(tmp[i]) < 58) {
        num += tmp[i];
        break;
      }
    }

    res += stoi(num);
  }

  std::cout << res;
}

int main()
{
  calibration();

  return 0;
}