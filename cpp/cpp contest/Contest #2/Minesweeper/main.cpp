#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>

void readBombs(char arr[], int bombs, int new_line)
{

}

void addClues(char arr[], int size, int new_line)
{

}

void printField(char arr[], int size, int new_line)
{

}

int main()
{
  int x, y, bombs;

  std::cin >> y >> x >> bombs;

  char field[y][x];

  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j < y; j++)
    {
      field[i][j] = '0';
    }
  }
  

  readBombs(field, bombs, x);
  addClues(field, y*x, x);
  printField(field, y*x, x);

  return 0;
}