#include <iostream>

void inputMatrix(int n, int m, int **matrix);
void reflection(int n, int m, int **matrix);
void outputMatrix(int n, int m, int **matrix);

void inputMatrix(int n, int m, int **matrix)
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> matrix[i][j];
    }
  }
}


void reflection(int n, int m, int **matrix)
{
  for (int i = 0; i < n/2; i++) {
    for (int j = 0; j < m; j++) {
      std::swap(matrix[i][j], matrix[(n-1)-i][j]);
    }
  }
}


void outputMatrix(int n, int m, int **matrix)
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << "\n";
  }
}


int main()
{
  int n, m;
  std::cin >> n >> m;

  int **matrix = new int*[n];

  for (int i = 0; i < n; i++) {
    matrix[i] = new int[m];
  }

  inputMatrix(n, m, matrix);
  reflection(n, m, matrix);
  outputMatrix(n, m, matrix);

  return 0;
}