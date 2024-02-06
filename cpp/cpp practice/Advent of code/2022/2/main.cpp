#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <fstream>

int game(char opponent, char player) 
{
  int res = 0;

  switch (player) {
    case 'X': //lose
      switch (opponent) {
        case 'A': //rock
          res += 3;
          break;
        
        case 'B': //paper
          res += 1;
          break;

        case 'C': //scissors
          res += 2;
          break;
      }
      break;
    
    case 'Y': //draw
      switch (opponent) {
        case 'A': //rock
          res += 4;
          break; 

        case 'B': //paper
          res += 5;
          break;
        
        case 'C': //scissors
          res += 6;
          break;
      }
      break;

    case 'Z': //win
      switch (opponent) {
        case 'A': //rock
          res += 8;
          break; 

        case 'B': //paper
          res += 9;
          break;
        
        case 'C': //scissors
          res += 7;
          break;
      }
      break;
  }

  return res;
}


int main()
{
  std::ifstream file("input.txt");
  std::string str;
  int res = 0;

  if (file.is_open()) {
    while (!file.eof()) {
      getline(file, str);
      res += game(str[0], str[2]);  
    }
  }

  std::cout << res;

  return 0;
}