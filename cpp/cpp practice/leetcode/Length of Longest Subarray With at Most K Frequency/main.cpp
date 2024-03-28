#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
int maxSubarrayLength(std::vector<int>& nums, int k)
{
  int res = 0, l = 0, r = 0;
  std::map<int, int> data;

  for (int r = 0; r < nums.size(); r++) {
    data[nums[r]]++;
    if (data[nums[r]] > k) {
      while (data[nums[l]] != data[nums[r]]) {
        data[nums[l]]--;
        l++;
      }

      data[nums[l]]--;
      l++;
    }
    res = std::max(res, r - l + 1);
  }

  return res;
}


int main()
{
  std::vector<int> nums = {1};
  int k = 1;

  std::cout << maxSubarrayLength(nums, k);

  return 0;
}
