///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Read a single integer n from the file. In another file, write a matrix filled 
/// in the following way:
/// 1   2   3   4
/// 8   7   6   5
/// 9   10  11  12
/// 16  15  14  13
///
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <sstream> 

void countFileStatistics(int n, int m);


void countFileStatistics(int n, int m) 
{
  int x = 0, y = 0, cnt = 1, curdir = 1, pos = 0;
  int data[n][m];
  int dir[2] = {0, m};

  for (int i = 0; i < n; i++) { 
    for (int j = dir[pos]-pos; j != dir[pos+curdir]-pos; j += curdir) {
      data[i][j] = cnt;
      cnt++;
    }

    curdir = -curdir;
    pos = (pos + 1) % 2;
  }
  

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
    {
      std::cout << data[i][j] << " ";
    }
    std::cout << std::endl;
  }
}


int main() {
  int n, m;

  std::cin >> n >> m;

  countFileStatistics(n, m);

  return 0;
}