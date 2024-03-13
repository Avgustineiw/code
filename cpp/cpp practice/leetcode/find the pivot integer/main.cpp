#include <iostream>
#include <vector>

int PivotInteger(int n) {
  int afterPivot, beforePivot; 
      
  std::vector<int> data;
    
  for (size_t i = 1; i < n; i++) {
    data.push_back(i);
  }

  for (size_t i = 1; i < n + 1; i++) {
    beforePivot = 0;
    afterPivot = 0;
    for (size_t j = 1; j < i + 1; j++) {
      beforePivot += j;
    }

    for (size_t j = i; j < n + 1; j++) {
      afterPivot += j;
    }

    if (beforePivot == afterPivot) {
      return i;
    }
  }
    
  return -1;
}


int main()
{
  int n;
  std::cin >> n;

  std::cout << PivotInteger(n) << '\n';

  return 0;
}
