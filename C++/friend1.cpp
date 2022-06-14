#include <bits/stdc++.h>
using namespace std;

// Note friend function is not a member function of the class. For an outsider function to access the private members of the class, the outsider function needs to have permission from the class which is given in the form of a friend keyword

class Complex
{
    int a;
    int b;

public:
    void setData(int v1, int v2)
    {
        a = v1;
        b = v2;
    }

    friend Complex setComplex(Complex, Complex);

    void printData(void)
    {
        cout << "The complex number is " << a << " + i" << b << endl;
    }
};

Complex setComplex(Complex o1, Complex o2)
{
    Complex o3;
    o3.setData((o1.a + o2.a), (o1.b + o2.b));
    return o3;
}

int main()
{
    Complex c1, c2, c3;
    c1.setData(1, 2);
    c1.printData();
    c2.setData(3, 4);
    c2.printData();
    c3 = setComplex(c1, c2);
    c3.printData();
    return 0;
}

/* Properties of friend functions
1. Not in the scope of class
2. since it is not in the scope of the class, it cannot be called from the object of that class. c1.sumComplex() == Invalid
3. Can be invoked without the help of any object
4. Usually contans the objects as arguments
5. Can be declared inside public or private section of the class
6. It cannot access the members directly by their names and need object_name.member_name to access any member.

*/