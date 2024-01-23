////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 4: "Length of a C-string (strlen)".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Count the length of a C-style string variable initialized with a string
/// literal (implement strlen() ).
///
////////////////////////////////////////////////////////////////////////////////
#include <iostream>

int mystrlen(char* str) //std::string& s
{
  int n, count = 0;
  int i = 0;

  while (str[i] != 0) {
    count += 1;
    i++;
  } 

  return count;
}

int main()
{
  int len = 0;
  char string[256] = "";

  char* w = string;
  char* y = string;


  std::cin >> string;
  len = mystrlen(string);

  y[0] = 'r';
  std::cout << len << std::endl;
  std::cout << y << " " << w;

  return 0;
}
