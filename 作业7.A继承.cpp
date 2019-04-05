#include <iostream>
using namespace std;
class Base
{
public:
    Base(int b)
    {
        m_x = b;
        cout<<"Base = "<<m_x<<" is created."<<endl;
    }
    ~Base()
    {
        cout<<"Base = "<<m_x<<" is erased."<<endl;
    }
    Base(const Base &b)
    {
        m_x = b.m_x;
        cout<<"Base = "<<m_x<<" is copied."<<endl;
    }
protected:
    int m_x;
};
class Derived : public Base
{
public:
    Derived(int a, int b) : Base(a)
    {
        m_y = b;
        cout<<"Derived = "<<m_y<<" is created."<<endl;
    }
    ~Derived()
    {
        cout<<"Derived = "<<m_y<<" is erased."<<endl;
    }
    Derived(const Derived &d) : Base(d)
    {
        m_y = d.m_y;
        cout<<"Derived = "<<m_y<<" is copied."<<endl;
    }

private:
    int m_y;
};
int main()
{
    int cases, data1, data2;
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        cin>>data1>>data2;
        Base base1(data1), base2(base1);

        Derived derived1(data1, data2), derived2(derived1);
    }
}
