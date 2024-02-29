#include <iostream>
#include <map>
#include <set>

int main()
{
  std::map<std::string, int> data;
  std::string name;
  int vote; 

  while (std::cin >> name >> vote) {
    if (data.find(name) == data.end()) {
      data[name] = vote;
    }
    else {
      data[name] += vote;
    }
  }

  for (std::map<std::string, int>::iterator it = data.begin(); it != data.end(); it++) {
    std::pair<std::string, int> x;
    x = *it;
    std::cout << x.first << " " << x.second << '\n';
  }

  return 0;
}