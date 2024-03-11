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
  std::vector<int> nums = {1,3,-1,-3,5,3,6,7};
  int tmp, k = 3;

  for (size_t i = 0; i < nums.size(); i++) {
    tmp = nums[i];
    data.insert(tmp);
    dq.push_back(tmp);

    if (dq.size() == k) {
      res.push_back(*data.rbegin());
      data.erase(data.find(dq.front()));
      dq.pop_front();
    }
  }

  for (size_t i = 0; i < res.size(); i++) {
    std::cout << res[i] << '\n';
  }

  return 0;
}