#include <bits/stdc++.h>
using namespace std;

class Employee
{
    int id;
    int salary;

public:
    void setId()
    {
        salary = 122;
        cout << "Enter the ID " << endl;
        cin >> id;
    }
    void getId()
    {
        cout << "The employee ID is " << id << endl;
    }
};

int main()
{
    Employee fb[4];
    for (int i = 0; i < 4; i++)
    {
        fb[i].setId();
        fb[i].getId();
    }
    return 0;
}