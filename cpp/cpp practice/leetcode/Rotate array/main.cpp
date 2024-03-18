#include <iostream>
#include <vector>

void rotate(std::vector<int>& nums, int k)
{
  int size = nums.size();
  std::vector<int> data(size, 0);

  for (size_t i = 0; i < size; i++) {
    int new_pos = i + k; 

    if (new_pos < size) 
      data[new_pos] = nums[i]; 
    else 
      data[new_pos % size] = nums[i];
  }

  for (size_t i = 0; i < size; i++) {
    nums[i] = data[i];
  }
}

int main()
{
  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  int k {2};

  rotate(nums, k);

  for (size_t i = 0; i < nums.size(); i++) {
    std::cout << nums[i] << " ";
  }
}
