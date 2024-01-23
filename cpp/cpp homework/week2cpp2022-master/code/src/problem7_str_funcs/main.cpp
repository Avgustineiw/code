////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 7: "Some functions for dealing with strings".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Try to use functions for dealing with strings:
/// 1) strcmp, strlen for c-strings;
/// 2) string:: size(), length(), operator<, operator+, operator= etc for
///    std::string-s.
///
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string.h>
#include <stdio.h>

int main()
{
  std::string string_1;
  std::string string_2;

  std::getline(std::cin, string_1);
  std::getline(std::cin, string_2);

  if (string_1 > string_2) {
    std::cout << "2" << std::endl;
  }
  else if (string_1 < string_2) {
    std::cout << "1" << std::endl;
  }
  else {
    std::cout << "Equal" << std::endl;
  }

  std::cout << string_1.length() << std::endl;
  std::cout << string_2.length() << std::endl;

  return 0; 
}


