#include <iostream>
#include <vector>
int numSubarrayProductLessThanK(std::vector<int>& nums, int k)
{
  int res = 0;
  int product = 1;
  int l = 0;
  if (k <= 1) {
    return 0;
  }

  for (size_t i = 0; i < nums.size(); i++) {
    product *= nums[i];
    
    while (product >= k) {
      product /= nums[l];
      l++;
    }

    res += 1 + (i - l);
  }

  return res;
}


int main()
{
  std::vector<int> nums = {10, 5, 2, 6};
  int k = 100;

  std::cout << numSubarrayProductLessThanK(nums, k);
  return 0;
}
