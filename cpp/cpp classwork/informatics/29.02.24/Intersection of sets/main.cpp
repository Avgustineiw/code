#include <iostream>
#include <sstream>
#include <set>

int main()
{
  std::set <int> data_1, data_2, intersect;
  std::string tmp_1, tmp_2;
  int n, v;

  getline(std::cin, tmp_1);
  getline(std::cin, tmp_2);
  
  std::stringstream ss_1(tmp_1);
  std::stringstream ss_2(tmp_2);

  while (ss_1 >> n) {
    data_1.insert(n);
  }

  while (ss_2 >> v) {
    data_2.insert(v);
  }

  std::set_intersection(data_1.begin(), data_1.end(), data_2.begin(), data_2.end(), 
                        std::inserter(intersect, intersect.begin()));

  for (std::set<int>::iterator it = intersect.begin(); it != intersect.end(); it++) {
    int x = *it;
    std::cout << x << " ";
  }
  return 0;
}