#include <algorithm>
#include <string>
int maxDepth(std::string s)
{
  int res = 0, cnt = 0;

  for (size_t i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      cnt++;
    }
    else if (s[i] == ')') {
      cnt--;
    }
    res = std::max(res, cnt);
  }

  return res;
}
