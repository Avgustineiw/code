#include <algorithm>
#include <iostream>
#include <vector>
int findMinArrowShots(std::vector<std::vector<int>>& points) {
  int size = points.size();
  int arrows = 1;
  int last = points[0][1];

  std::sort(points.begin(), points.end());

  for (size_t i = 0; i < size; i++) {
    std::cout << points[i][0] << " " << points[i][1] << '\n';
  }

  for (size_t i = 0; i < size; i++) {
    if (points[i][0] > last) {
      arrows++;
      last = points[i][1];
    }
    else 
      last = std::min(last, points[i][1]);

    // std::cout << "DEBUG: " << points[i][0] << " " <<points[i][1] << " : " << last << '\n'; 
  }
    
  return arrows;
}

int main()
{
  std::vector<std::vector<int>> points = {{10, 16}, {2,8}, {1,6}, {7,12}};
  
  int res = findMinArrowShots(points);

  std::cout << res;

  return 0;
}
