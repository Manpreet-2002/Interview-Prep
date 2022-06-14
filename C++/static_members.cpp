#include <bits/stdc++.h>
using namespace std;
// Count is the static data member of the class Employee
// Static member functions can only access static members. getCount() is static function.
class Employee
{
    int id;
    static int count; // Property of the entire class and its scope is the class

public:
    void setData()
    {
        cout << "Enter the id" << endl;
        cin >> id;
        count++;
    };
    void getData()
    {
        cout << "ID of the employee is " << id << " and this is employee number " << count << endl;
        ;
    };

    static void getCount(void)
    {
        cout << "The value of count is " << count << endl;
    };
};

int Employee ::count; // We initialize it outside the class coz this memory gets allocated to the class. Default value is 0.

int main()
{
    Employee Manpreet, Ravpreet, Harry;
    Manpreet.setData();
    Manpreet.getData();
    Employee ::getCount();

    Ravpreet.setData();
    Ravpreet.getData();
    Employee ::getCount();

    Harry.setData();
    Harry.getData();
    Employee ::getCount();
    return 0;
}