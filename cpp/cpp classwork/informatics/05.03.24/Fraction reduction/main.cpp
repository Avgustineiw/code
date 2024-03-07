#include <iostream>
#include <numeric>

struct rational
{
  int num;
  int denom;
  int div;

  rational(int _num = 0, int _denom = 1) {
    div = std::gcd(_num, _denom);

    num = _num / div;
    denom = _denom / div;

    if (div < 0) {
      num = -num;
      denom = -denom;
    }
  };
};

rational operator+(rational A, rational B)
{
  rational C(A.num*B.denom + A.denom*B.num, A.denom*B.denom);
  return C;
}

rational operator-(rational A, rational B)
{
  rational C(A.num*B.denom - A.denom*B.num, A.denom*B.denom);
  return C;
}


rational operator*(rational A, rational B)
{
  rational C(A.num*B.num, B.denom*A.denom);
  return C;
}

rational operator/(rational A, rational B)
{
  rational C(B.denom, B.num);
  return (A*B);
}

int main()
{
  int num_1, denom_1, div = 0;
  int num_2, denom_2;
  std::cin >> num_1 >> denom_1 >> num_2 >> denom_2;

  rational frac_1(num_1, denom_1);
  rational frac_2(num_2, denom_2);

  rational frac = frac_1 + frac_2;

  std::cout << frac.num << " " << frac.denom;
} 