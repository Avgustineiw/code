
#include <iostream>
#include <map>
#include <vector>
std::vector<int> findDuplicate(std::vector<int>& nums)
{
  std::map<int, int> data;
  std::vector<int> res;

  for (size_t i = 0; i < nums.size(); i++) {
    if (data.count(nums[i]) != 0) {
      res.push_back(nums[i]);
    }
    else {
      data[nums[i]]++;
    }
  }

  return res;
}

int main()
{
  std::vector<int> nums = {1, 3, 4, 2, 2};
}
