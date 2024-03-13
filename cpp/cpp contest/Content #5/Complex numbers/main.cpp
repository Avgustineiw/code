#include <cmath>
#include <iostream>

class Complex {
public:
    double re_;
    double im_;

    Complex(double re = 0, double im = 0)
    {
        re_ = re;
        im_ = im;
    }

    Complex operator+(Complex);
    Complex operator-(Complex);
    Complex operator*(Complex);
    Complex operator/(Complex);

    Complex operator+() const
    {
        Complex C;
        C.re_ = +re_;
        C.im_ = +im_;
        return C;
    }

    Complex operator-() const
    {
        Complex C;
        C.re_ = -re_;
        C.im_ = -im_;
        return C;
    }

    double Re() const
    {
        return re_;
    }

    double Im() const
    {
        return im_;
    }
};

Complex Complex::operator+(Complex C)
{
    Complex temp;
    temp.re_ = re_ + C.re_;
    temp.im_ = im_ + C.im_;
    return temp;
}

Complex Complex::operator-(Complex C)
{
    Complex temp;
    temp.re_ = re_ - C.re_;
    temp.im_ = im_ - C.im_;
    return temp;
} 


Complex Complex::operator*(Complex C)
{
    Complex temp;
    temp.re_ = re_ * C.re_ - im_ * C.im_;
    temp.im_ = re_ * C.im_ + im_ * C.re_;
    return temp;
}

Complex Complex::operator/(Complex C)
{
    Complex temp;
    temp.re_ = (re_ * C.re_ + im_ * C.im_) / (pow(C.re_, 2) + pow(C.im_, 2));
    temp.im_ = (im_ * C.re_ - re_ * C.im_) / (pow(C.re_, 2) + pow(C.im_, 2));
    return temp;
}

Complex operator+(double num, const Complex& C)
{
    Complex temp;
    temp.re_ = num + C.Re();
    temp.im_ = C.Im();
    return temp;
}

Complex operator-(double num, const Complex& C)
{
    Complex temp;
    temp.re_ = num - C.Re();
    temp.im_ = C.Im();
    return temp;
}

Complex operator*(double num, const Complex& C)
{
    Complex temp;
    temp.re_ = num * C.re_;
    temp.im_ = num * C.im_;
    return temp;
}

Complex operator/(double num, const Complex& C)
{
    Complex temp;
    temp.re_ = (num * C.re_) / (pow(C.re_, 2) + pow(C.im_, 2));
    temp.im_ = (-num * C.im_) / (pow(C.re_, 2) + pow(C.im_, 2));
    return temp;
}

double abs(const Complex& num)
{
    double res = 0;

    res += sqrt(pow(num.Re(), 2) + pow(num.Im(), 2));

    return res;
}

bool operator==(const Complex& num1, const Complex& num2)
{
    return num1.Re() == num2.Re() && num1.Im() == num2.Im();
}

bool operator!=(const Complex& num1, const Complex& num2)
{
    return num1.Re() != num2.Re() || num1.Im() != num2.Im();
}

int main()
{
    Complex num1(5, 7);
    Complex num2(5);
    Complex num3 = 2 * num1;
    std::cout << num3.Re() << " " << num3.Im();

    // return 0;
}


