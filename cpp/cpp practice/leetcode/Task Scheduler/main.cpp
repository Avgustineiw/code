#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
int leastInterval(std::vector<char>& tasks, int n)
{
  int interval = 0, maxx = 0, freq = 0;
  int size = tasks.size();
  std::map<char, int> data;

  for (size_t i = 0; i < size; i++) {
    data[tasks[i]]++;

    if (maxx < data[tasks[i]])
      maxx = data[tasks[i]];
  }


  for (const auto& ele: data) {
    if (ele.second == maxx) 
      freq++;
  }

  interval = (maxx - 1) * (n + 1) + freq;

  std::cout << interval << '\n';

  // for (const auto& ele: data) {
  //   std::cout << ele.first << " " << ele.second << '\n';
  // }

  return std::max(interval, size);
}


int main()
{
  std::vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};

  leastInterval(tasks, 2);

  return 0;
}
