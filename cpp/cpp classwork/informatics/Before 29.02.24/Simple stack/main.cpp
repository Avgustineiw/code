#include <iostream>
#include <string>
#include <vector>

const int maxsize = 105;

struct vec
{
  int data[maxsize];
  int size_n;

  vec() {
    size_n = 0;
  }

  ~vec() {}

  void push(int x) {
    data[size_n] = x;
    size_n++;
  }

  int pop() {
    size_n--;
    return data[size_n];
  }

  int back() {
    return data[size_n-1];
  }

  int size() {
    return size_n;
  }

  void clear() {
    size_n = 0;
  }

  std::string exit() {
    return "bye";
  }
};


int main()
{
  std::string tmp;
  std::vector<std::string> res;
  int n;
  vec ss;

  while (std::cin >> tmp) {
    if (tmp == "push") {
      std::cin >> n;
      ss.push(n);
      res.push_back("ok");
    }
    else if (tmp == "pop") {
      res.push_back(std::to_string(ss.pop()));
    }
    else if (tmp == "back") {
      res.push_back(std::to_string(ss.back()));
    }
    else if (tmp == "size") {
      res.push_back(std::to_string(ss.size()));
    }
    else if (tmp == "clear") {
      ss.clear();
      res.push_back("ok");
    }
    else if (tmp == "exit") {
      res.push_back("bye");
      break;
    }
  }

  for (int i = 0; i < res.size(); i++) {
    std::cout << res[i] << '\n';
  }

  return 0;
}