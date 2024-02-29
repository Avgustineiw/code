#include <iostream>
#include <string>
#include <vector>

const int maxsize = 105;

struct vec
{
  int* data;
  int* old_data;
  int size_n, capacity;

  vec() {
    capacity = maxsize;
    data = new int[capacity];
    size_n = 0;
  }

  ~vec() {
    delete data;
  }

  void push(int x) {
    if (size_n == capacity) {
      old_data = data;
      capacity *= 2;
      data = new int[capacity];

      for (int i = 0; i < size_n; i++) {
        data[i] = old_data[i];
      }

      delete old_data;
    }

    data[size_n] = x;
    size_n++;
  }

  std::string pop() {
    if (size_n > 0) {
      size_n--;
      return std::to_string(data[size_n]);
    }
    else {
      return "error";
    }
  }

  std::string back() {
    if (size_n > 0) {
      return std::to_string(data[size_n-1]);
    }
    else {
      return "error";
    }
  }

  std::string size() {
    return std::to_string(size_n);
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
      res.push_back(ss.pop());
    }
    else if (tmp == "back") {
      res.push_back(ss.back());
    }
    else if (tmp == "size") {
      res.push_back(ss.size());
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