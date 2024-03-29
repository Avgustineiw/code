#include <algorithm>
#include <iostream>
#include <vector>
long long countSubarrays(std::vector<int>& nums, int k)
{
  long long int res = 0;
  long long int maxx = *std::max_element(nums.begin(), nums.end());
  long long int cnt = 0;
  long long int l = 0;

  for (size_t r = 0; r < nums.size(); r++) {
    if (nums[r] == maxx) {
      cnt++;
    }

    while (cnt >= k) {
      if (nums[l] == maxx) {
        cnt--;
      }
      l++;
      res += nums.size() - r;
    }
  }

  return res;
}


int main()
{
  std::vector<int> nums = {1, 3, 2, 3, 3};
  int k = 2;

  std::cout << countSubarrays(nums, k);
  return 0;
}
