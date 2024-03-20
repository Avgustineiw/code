#include <iostream>

int camp(int intro, int extra, int uni)
{
  int res = 0;

  if (extra % 3 == 0) {
    res += extra/3;
  }
  else {
    for (size_t i = uni; i >= 0; i--) {
      if ((extra + i) % 3 == 0) {
        res += (extra + i) / 3;
        uni -= i;
        break;
      }

      if (i == 0) 
        return -1;
    }
  }

  res += intro;
  if (uni % 3 == 0) 
    res += uni/3;
  else if (uni % 2 == 0)
    res += uni/2;
  else
    res += uni;
  

  return res;
}

int main()
{
  int n;
  std::cin >> n;

  while (n >= 0) {
    int res = 0, intro, extra, uni;
    std::cin >> intro >> extra >> uni;

    res = camp(intro, extra, uni);

    std::cout << res << '\n';
  }
}
