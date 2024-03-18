#include <algorithm>
#include <iostream>
#include <vector>
std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval)
{
  std::vector<std::vector<int>>  res;
  std::vector<int> buffer;
  int size = intervals.size();

  for (size_t i = 0; i < size; i++) {
    if (newInterval[1] < intervals[i][0]) {
        res.push_back(newInterval);
        res.insert(res.end(), intervals.begin()+i, intervals.end());
        return res;
    }
    else if (newInterval[0] > intervals[i][1]) {
      res.push_back(intervals[i]);
    }
    else {
      newInterval = {std::min(newInterval[0], intervals[i][0]), std::max(newInterval[1], intervals[i][1])};
    }
  }

  res.push_back(newInterval);


  return res;
}


int main()
{
  std::vector<std::vector<int>> intervals = {{1,2}, {3,5}, {6,7}, {8,10}, {12,16}};
  std::vector<std::vector<int>> res;
  std::vector<int> newInterval = {4, 8};

  res = insert(intervals, newInterval);

  for (size_t i = 0; i < res.size(); i++) {
      std::cout << res[i][0] << " " << res[i][1] << '\n';
  }
}
