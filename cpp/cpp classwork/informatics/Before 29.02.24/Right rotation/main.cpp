#include <iostream>

void inputMatrix(int n, int **matrix);
void rotation(int n, int **matrix);
void outputMatrix(int n, int **matrix);

void inputMatrix(int n, int **matrix)
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> matrix[i][j];
    }
  }
}


void rotation(int n, int **matrix, int **res)
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res[i][j] = matrix[(n-1)-j][i];
    }
  }
}


void outputMatrix(int n, int **matrix)
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << "\n";
  }
}


int main()
{
  int n;
  std::cin >> n;

  int **matrix = new int*[n];
  int **res = new int*[n];

  for (int i = 0; i < n; i++) {
    matrix[i] = new int[n];
    res[i] = new int[n];
  }

  inputMatrix(n, matrix);
  rotation(n, matrix, res);
  outputMatrix(n, res);

  return 0;
}