#include <iostream>
#include <map>
#include <vector>
int findDuplicate(std::vector<int>& nums)
{
  std::map<int, int> data;

  for (size_t i = 0; i < nums.size(); i++) {
    if (data.count(nums[i]) != 0) {
      return nums[i];
    }
    else {
      data[nums[i]]++;
    }
  }

  return 0;
}

int main()
{
  std::vector<int> nums = {1, 3, 4, 2, 2};

  std::cout << findDuplicate(nums);
}
