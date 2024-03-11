#include <iostream>
#include <numeric>

struct Rational
{
  int num;
  int denom;
  int div;

  Rational(int _num = 0, int _denom = 1) {
    div = std::gcd(_num, _denom);

    num = _num / div;
    denom = _denom / div;

    if (div < 0) {
      num = -num;
      denom = -denom;
    }
  };
};

Rational operator+(Rational A, Rational B)
{
  Rational C(A.num*B.denom + A.denom*B.num, A.denom*B.denom);
  return C;
}

Rational operator-(Rational A, Rational B)
{
  Rational C(A.num*B.denom - A.denom*B.num, A.denom*B.denom);
  return C;
}


Rational operator*(Rational A, Rational B)
{
  Rational C(A.num*B.num, B.denom*A.denom);
  return C;
}

Rational operator/(Rational A, Rational B)
{
  Rational C(B.denom, B.num);
  return (A*B);
}

int main()
{
  int num_1, denom_1, div = 0;
  int num_2, denom_2;
  std::cin >> num_1 >> denom_1 >> num_2 >> denom_2;

  Rational frac_1(num_1, denom_1);
  Rational frac_2(num_2, denom_2);

  Rational frac = frac_1 + frac_2;

  std::cout << frac.num << " " << frac.denom;
} 