#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>

void readBombs(char **field, int bombs)
{
  int bomb_row, bomb_col;

  for (int i = 0; i < bombs; i++) {
    std::cin >> bomb_row >> bomb_col;

    field[bomb_row-1][bomb_col-1] = '*';
  }
}

int BombNearby(int pos_row, int pos_col, int row, int col, char **field)
{
  int nearby[8][2] = {{pos_row+1,  pos_col},
                       {pos_row,   pos_col+1},
                       {pos_row+1, pos_col+1},
                       {pos_row-1, pos_col},
                       {pos_row,   pos_col-1},
                       {pos_row-1, pos_col-1},
                       {pos_row+1, pos_col-1},
                       {pos_row-1, pos_col+1}};
  int res = 0;

  for (int i = 0; i < 8; i++) {
    if ((0 <= nearby[i][0] && nearby[i][0] < row)&&(0 <= nearby[i][1] && nearby[i][1] < col)) {
      if (field[nearby[i][0]][nearby[i][1]] == '*') {
        res++;
      }
    }
  }
  
  return res;
}


void addClues(int row, int col, char **field)
{
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (field[i][j] != '*') {
        field[i][j] = char(int(field[i][j] + BombNearby(i, j, row, col, field)));
      }
    }
  }
}


void printField(int row, int col, char **field)
{
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      std::cout << field[i][j] << " ";
    }
    std::cout << std::endl;
  }
}


int main()
{
  int row, col, bomb;

  std::cin >> row >> col >> bomb;

  char **field = new char*[row];

  for (int i = 0; i < row; i++) {
    field[i] = new char[col];
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      field[i][j] = '0';
    }
  }
  
  readBombs(field, bomb);
  addClues(row, col, field);
  printField(row, col, field);

  return 0;
}