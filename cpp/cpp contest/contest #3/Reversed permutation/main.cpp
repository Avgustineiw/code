#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> arr(n, 0), res(n, 0);

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
    arr[i] -= 1;
  }

  for (int i = 0; i < n; i++) {
    res[arr[i]] = i;
  }

  for (int i = 0; i < n; i++) {
    std::cout << res[i] + 1 << " ";
  }

  return 0;
}