#include <iostream>
#include <unordered_map>
#include <vector>

int sumSubarrayWithSum(std::vector<int>& nums, int goal) {
  std::unordered_map<int, int> mp;
  int sum = 0, res = 0;

  for (size_t i = 0; i < nums.size(); i++) {
    sum += nums[i];

    if (sum == goal)
      res++;

    if (mp.find(sum-goal) != mp.end())
      res += mp[sum-goal];
    
    if (mp.find(sum) != mp.end()) 
      mp[sum]++;
    else 
      mp[sum] = 1;
  }

  return res;
}

int main()
{
  int n = 0;
  std::vector<int> nums = {0,0,0,0,0};

  std::cout << sumSubarrayWithSum(nums, n);
}
