#include <iostream>
#include <stdlib.h>
#include <string>

int remainder(int m, std::string str) 
{
  int mod = 0;

  for (int i = 0; i < str.length(); i++)
  {
    int num = (str[i] - '0');
    
    mod = mod * 10 + num;
    mod = mod % m;
  }

  return mod;
}

int main()
{
  std::string n;
  int k;

  std::cin >> k >> n;

  std::cout << remainder(k, n);

  return 0;
}