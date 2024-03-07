#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <utility>

bool cmp(std::pair<std::string, int> pair_1, std::pair<std::string, int> pair_2)
{
  if (pair_1.second == pair_2.second) 
    return pair_1.first <= pair_2.first;
    
  return pair_1.second > pair_2.second;
}

int main()
{
  std::string line, word; 
  std::map<std::string, int> data;
  while (getline(std::cin, line)) {
    std::stringstream ss(line);

    while (ss >> word) {
      data[word]++;
    }
  }

  std::vector<std::pair<std::string, int>> res;

  for (std::pair _pair: data) {
    res.push_back(_pair);
  }

  sort(res.begin(), res.end(), cmp);

  for (int i = 0; i < res.size(); i++) {
    std::cout << res[i].first << '\n';
  }
}