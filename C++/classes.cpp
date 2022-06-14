#include <bits/stdc++.h>
using namespace std;

class Employee
{
private:
    int a, b, c;

public:
    int d, e;
    void setdata(int a1, int b1, int c1);
    void getdata()
    {
        cout << "Value of a is " << a << endl;
        cout << "Value of b is " << b << endl;
        cout << "Value of c is " << c << endl;
        cout << "Value of d is " << d << endl;
        cout << "Value of e is " << e << endl;
    };
};

void Employee ::setdata(int a1, int b1, int c1)
{
    a = a1;
    b = b1;
    c = c1;
};

int main()
{
    Employee Manpreet;
    Manpreet.d = 7;
    Manpreet.e = 1;
    Manpreet.setdata(1, 2, 4);
    Manpreet.getdata();
    return 0;
}