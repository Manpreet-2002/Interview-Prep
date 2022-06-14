#include <bits/stdc++.h>
using namespace std;

// Forward declaration
class Complex;

class Calculator
{
public:
    int add(int a, int b)
    {
        return a + b;
    }
    int sumReal(Complex o1, Complex o2);
};

class Complex
{
    int a;
    int b;

    // Individually declaring the functions of a class as friend
    friend int Calculator ::sumReal(Complex, Complex);

    // Aliter: Declaring the entire calculator class as friend
    friend class Calculator;

public:
    void setData(int v1, int v2)
    {
        a = v1;
        b = v2;
    }

    void printData(void)
    {
        cout << "The complex number is " << a << " + i" << b << endl;
    }
};

int Calculator ::sumReal(Complex o1, Complex o2)
{
    return (o1.a + o2.a);
}

int main()
{
    Complex o1, o2;
    Calculator calc;
    o1.setData(1, 4);
    o2.setData(5, 7);
    int res = calc.sumReal(o1, o2);
    cout << "The sum of real parts of o1 and o2 is " << res << endl;
    return 0;
}