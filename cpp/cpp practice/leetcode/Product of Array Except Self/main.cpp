#include <iostream>
#include <vector>
std::vector<int> productExceptSelf(std::vector<int>& nums) 
{
  int size = nums.size();
  std::vector<int> left_product(size, 1), right_product(size, 1);
  std::vector<int> res;
  
  for (int i = 1; i < size; i++) {
    left_product[i] = left_product[i-1] * nums[i-1]; 
  }

  for (int i = size - 2; i >= 0; i--) {
    right_product[i] = right_product[i+1] * nums[i+1];
  }

  for (int i = 0; i < size; i++) {
    res.push_back(right_product[i] * left_product[i]);
  }


  for (int i = 0; i < size; i++) {
    std::cout << res[i] << '\n';
  }

  return res;
}


int main()
{
  std::vector<int> nums = {1, 2, 3, 4};

  productExceptSelf(nums);
}
