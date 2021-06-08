#include<complex.h>
#include <complex>
#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;
class Complex
{
private:


public:

    double real;
    double image;

    Complex(double r = 0, double i = 0) { real = r, image = i; }

    Complex operator+(const Complex&);
    Complex operator-(const Complex&);
    Complex operator*(const Complex&);
    Complex operator/(const Complex&);

    friend ostream &operator<<(ostream&, const Complex &);

    friend istream& operator>>(istream&, Complex&);
};

Complex Complex::operator+(const Complex& fp1)
{
    Complex t(*this);
    t.real += fp1.real;
    t.image += fp1.image;
    return t;
}

Complex Complex::operator-(const Complex& fp1)
{
    Complex t(*this);
    t.real -= fp1.real;
    t.image -= fp1.image;
    return t;
}

Complex Complex::operator*(const Complex& fp1)
{
    double i, j;
    i = real * fp1.real - image * fp1.image;
    j = real * fp1.image + fp1.real * image;
    Complex t(i, j);
    return t;
}

Complex Complex::operator/(const Complex& fp1)
{
    double k, i, j;
    k = fp1.real * fp1.real + fp1.image * fp1.image;
    i = (real * fp1.real + image * fp1.image) / k;
    j = (fp1.real * image - real * fp1.image) / k;
    Complex t(i, j);
    return t;
}

ostream& operator<< (ostream& fo, const Complex& fp)
{
    if (fp.image < 0) fo << fp.real << "+i(" << fp.image << ")\n";
    else fo << fp.real << "+i" << fp.image << "\n";

    return fo;
}

istream& operator>>(istream& fi, Complex& fp)
{
    fi >> fp.real;
    fi >> fp.image;
    return fi;

}

class ComplexExp : public Complex
{
  public:

    void expCount(Complex x) {
      auto z = std::complex<double>(x.real, x.image);
      auto w = std::exp(z);
      std::cout << w << std::endl;
    }
};



int main()
{

    Complex c1, c2;

    setlocale(LC_ALL, "Rus");
    cout << "1 число, введите действительную и мнимую части через пробел: ";
    cin >> c1;
    cout << "2 число, введите действительную и мнимую части через пробел: ";
    cin >> c2;

    cout << "c1 = " << c1;
    cout << "c2 = " << c2 << '\n';

    cout << "c1 + c2 = " << c1 + c2;
    cout << "c1 - c2 = " << c1 - c2;
    cout << "c1 * c2 = " << c1 * c2;
    cout << "c1 / c2 = " << c1 / c2;

    cout << "c1 + 1 = " << c1 + 1;
    cout << "c1 - 1 = " << c1 - 1;
    cout << "c1 * 1 = " << c1 * 1;
    cout << "c1 / 1 = " << c1 / 1;

    ComplexExp *exp1 = new ComplexExp();
    exp1->expCount(c1);


    system("pause");
    return 0;

}
