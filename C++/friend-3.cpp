#include <bits/stdc++.h>
using namespace std;

class Y;

class X
{
    int data;
    friend int add(X, Y);
    friend void swapp(X &, Y &);

public:
    void setData(int _data)
    {
        data = _data;
    }
    void printData()
    {
        cout << data << endl;
    }
};
class Y
{
    int data;
    friend int add(X, Y);
    friend void swapp(X &, Y &);

public:
    void setData(int _data)
    {
        data = _data;
    }
    void printData()
    {
        cout << data << endl;
    }
};

int add(X o1, Y o2)
{
    return o1.data + o2.data;
}

void swapp(X &o1, Y &o2) // Remember to call by reference
{
    int temp = o1.data;
    o1.data = o2.data;
    o2.data = temp;
}
int main()
{
    X a1;
    Y b1;
    a1.setData(4);
    a1.printData();
    b1.setData(8);
    b1.printData();
    cout << "ADD returns " << add(a1, b1) << endl;
    swapp(a1, b1);
    a1.printData();
    b1.printData();
    return 0;
}