#include <iostream>
#include <numeric>

class Rational {
public:
    int num;
    int denom;
    int div;

    Rational(int _num = 0, int _denom = 1)
    {
        div = std::gcd(_num, _denom);

        num = _num / div;
        denom = _denom / div;

        if (denom < 0) {
            num = -num;
            denom = -denom;
        }
    }

    int numerator() const
    {
        return num;
    }

    int denominator() const
    {
        return denom;
    }

    Rational operator=(const Rational& other)
    {
        num = other.num;
        denom = other.denom;
        return *this;
    }

    Rational operator=(const int value)
    {
        num = value;
        denom = 1;
        return *this;
    }

    Rational operator+(const Rational& other) const
    {
        return Rational { num * other.denom + other.num * denom, denom * other.denom };
    }
    Rational operator+(const int& other) const
    {
        return Rational { num + other * denom, denom };
    }
    Rational operator+=(const Rational& other)
    {
        *this = *this + other;
        return *this;
    }

    Rational operator-(const Rational& other) const
    {
        return -other + *this;
    }
    Rational operator-(const int other) const
    {
        return Rational { num - other * denom, denom };
    }
    friend Rational operator-(const int num, const Rational& other)
    {
        return Rational { num * other.denom - other.num, other.denom };
    }
    Rational operator-=(const Rational& other)
    {
        *this = *this - other;
        return *this;
    }

    Rational operator*(const Rational& other) const
    {
        return Rational { num * other.num, denom * other.denom };
    }
    Rational operator*(const int other) const
    {
        return Rational { other * num, denom };
    }
    friend Rational operator*(const int num, const Rational& other)
    {
        return Rational { num * other.num, other.denom };
    }
    Rational operator*=(const Rational& other)
    {
        *this = *this * other;
        return *this;
    }

    Rational operator/(const Rational& other)
    {
        return Rational { num * other.denom, denom * other.num };
    }
    Rational operator/=(const Rational& other)
    {
        *this = *this / other;
        return *this;
    }

    Rational operator-() const
    {
        return Rational { -num, denom };
    }
    Rational operator+() const
    {
        return Rational { num, denom };
    }

    Rational& operator++()
    {
        *this += 1;
        return *this;
    }

    Rational operator++(int)
    {
        Rational old = *this;
        operator++();
        return old;
    }

    Rational& operator--()
    {
        *this -= 1;
        return *this;
    }

    Rational operator--(int)
    {
        Rational old = *this;
        operator--();
        return old;
    }
};

bool operator==(const Rational A, const Rational B)
{
    return (A.num == B.num && A.denom == B.denom);
}

bool operator!=(const Rational A, const Rational B)
{
    return (A.num != B.num || A.denom != B.denom);
}

int main()
{
    Rational frac_1(2, 3);
    Rational frac_2(-1, 2);

    Rational frac;

    frac = 3 * frac_2;
    std::cout << frac.num << " " << frac.denom;
}