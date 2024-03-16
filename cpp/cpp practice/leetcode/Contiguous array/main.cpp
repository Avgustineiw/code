#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
int findMaxLength(std::vector<int>& nums) {
  std::map<int, int> data;
  int cnt = 0;
  int max_length = 0;
  data[0] = -1;

  for (size_t i = 0; i < nums.size(); i++) {
    if (nums[i] == 0) 
      cnt -= 1;
    else 
      cnt += 1;

    if (data.count(cnt) != 0) {
      int val = i - data.find(cnt)->second;
      max_length = std::max(max_length, val);
    }
    else 
      data[cnt] = i;
  }

  std::cout << max_length;

  return max_length;
}


int main()
{
  std::vector<int> nums = {0, 1, 0, 1};

  for (size_t i = 0; i < nums.size(); i++) {
    std::cout << nums[i] << " ";
  }

  findMaxLength(nums);
}
