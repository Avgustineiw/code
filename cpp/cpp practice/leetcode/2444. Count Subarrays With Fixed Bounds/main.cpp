#include <algorithm>
#include <iostream>
#include <vector>
long long countSubarrays(std::vector<int>& nums, int minK, int maxK)
{
  int res = 0, cur_out = -1, cur_min = -1, cur_max = -1;

  for (size_t i = 0; i < nums.size(); i++) {
    if (nums[i] < minK || nums[i] > maxK) 
      cur_out = i;
    if (nums[i] == minK) 
      cur_min = i;
    if (nums[i] == maxK) 
      cur_max = i;

    res += std::max(0, std::min(cur_max, cur_min) - cur_out);
  }
  
  return res;
}


int main()
{
  std::vector<int> nums = {1, 3, 5, 2, 7 ,5};
  int minK = 1, maxK = 5;
  
  std::cout << countSubarrays(nums, minK, maxK);
  return 0;
}
