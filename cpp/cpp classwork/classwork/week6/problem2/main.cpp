///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Create program to read data from a CSV file (comma separated) 
/// and calculate the res value in each column. Separate into function
///
///////////////////////////////////////////////////////////////////////////////
#include <fstream> 
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

void readCSV(const std::string& inputCSVPath);

void readCSV(const std::string& inputCSVPath)
{
  std::ifstream csv(inputCSVPath);
  std::vector<std::vector<int>> data;
  std::string line, word;
  int row = 0, col = 0, res;

  while (!csv.eof()) {
    getline(csv, line);
    std::stringstream iss(line);

    data.push_back(std::vector<int>());

    while (getline(iss, word, ',')) {
      data[row].push_back(stoi(word));
      col++;
    }

    row++;
  }

  for (int i = 0; i < data.size(); i++) {
    res = 0;
    for (int j = 0; j < data[i].size(); j++) {
      res += data[j][i];
      // std::cout << data[i][j] << " ";
    }
    std::cout << res << std::endl;
    // std::cout << std::endl;
  }
}


int main() 
{
  readCSV("input.csv");

  return 0;
}