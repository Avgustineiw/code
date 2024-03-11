#include <algorithm>
#include <iostream>
#include <set>
#include <deque>
#include <vector>

int main()
{
  std::deque<int> dq;
  std::multiset<int> data;
  std::vector<int> res;
  unsigned int length, window;
  int tmp;

  std::cin >> length >> window;

  while (std::cin >> tmp) {
    data.insert(tmp);
    dq.push_back(tmp);

    if (dq.size() == window) {
      res.push_back(*data.begin());
      data.erase(data.find(dq.front()));
      dq.pop_front();
    }
  }

  for (size_t i = 0; i < length - window + 1; i++) {
    std::cout << res[i] << '\n';
  }

  return 0;
}