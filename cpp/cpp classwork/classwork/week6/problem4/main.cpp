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
/// 12  13  14  5
/// 11  16  15  6
/// 10  9   8   7
///
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <sstream> 

void countFileStatistics(int n, int m);


void countFileStatistics(int n, int m)
{
  int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int cnt = 1, x = 0, y = -1, d_row = dir[0][0], d_col = dir[0][1], pos = 0;
  int data[n][m];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      data[i][j] = 0;
    }
  }

  while (cnt <= n * m) {
    if ((x + d_row >= 0 && x + d_row < n) &&
        (y + d_col >= 0 && y + d_col < m) &&
        (data[x+d_row][y+d_col] == 0)) {
          x += d_row;
          y += d_col;
          data[x][y] = cnt;
          cnt++;
        }
    else {
      pos++;
      if (pos == 4) {
        pos = 0;
      }
      d_row = dir[pos][0];
      d_col = dir[pos][1];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
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