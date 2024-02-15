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

void countFileStatistics(const std::string& filePath, int n, int m);
bool correct(int x, int y, int n, int m);

bool correct(int x, int y, int n, int m) 
{
  return x >= 0 && x < n && y >= 0 && y < m;
}

void countFileStatistics(const std::string& filePath, int n, int m) 
{
  int x = 0, y = 0, cnt = 0, curdir = 0;
  int data[x][y];
  int dir[2][2] = {{0,1}, {0, -1}};

  while (cnt < n * m) { 
    data[x][y] = cnt;
    cnt++;
    int nx = x + dir[curdir][0];
    int ny = y + dir[curdir][1];
    if (!correct(nx, ny, n, m)) {
      nx = nx + 1;
      curdir = (curdir + 1) % 2;
    }
    else {
      x = nx;
      y = ny;
    }
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

  countFileStatistics("file.txt", n, m);

  return 0;
}