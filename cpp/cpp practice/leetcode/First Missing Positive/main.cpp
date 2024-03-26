#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
int firstMissingPositive(std::vector<int>& nums)
{
  std::set<int> data;
  std::sort(nums.begin(), nums.end());

  for (size_t i = 0; i < nums.size(); i++) {
    if (nums[i] > 0 && nums[i] < nums.size() + 1) {
      data.insert(nums[i]);
    }
  }

  int cnt = 1;
  for (auto& num: data) {
    // std::cout << num << '\n';
    if (num != cnt) {
      return cnt;
    }
    cnt++;
  }
  return data.size() + 1;
}

int main()
{
  std::vector<int> nums = {1, 2, 3};
  
  std::cout << firstMissingPositive(nums) << '\n';

  return 0;
}
