#include <iostream>
#include <map>
#include <vector>
int subarraysWithKDistinct(std::vector<int>& nums, int k) 
{
  int res = 0, far = 0, near = 0;
  std::map<int, int> data;
  
  for (size_t r = 0; r < nums.size(); r++) {
    data[nums[r]]++;

    while (data.size() > k) {
      data[nums[near]]--;

      if (data[nums[near]] == 0) {
        data.erase(nums[near]);
      }

      near++;
      far = near;
    }

    while (data[nums[near]] > 1) {
      data[nums[near]]--;
      near++;
    }

    if (data.size() == k) {
      res += near - far + 1;
    }
  }

  return res;
}


int main()
{
  std::vector<int> nums = {1, 2, 1, 2, 3};
  int k = 2;

  std::cout << subarraysWithKDistinct(nums, k);

  return 0;
}
