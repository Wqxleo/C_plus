#include <iostream>
using namespace std;
class Base
{
public:
    Base(int n)
    {
        m_n = n;
        cout<<"Base "<<m_n<<" is created."<<endl;
    }
    ~Base()
    {
        cout<<"Base "<<m_n<<" is created."<<endl;
    }
protected:
    int m_n;
};
class Derived : public Base
{
public:
    Derived(int n,int m) : Base(n)
    {
        m_m = m;
        cout<<"Derived "<<m_m<<" is created."<<endl;

    }
    ~Derived()
    {
        cout<<"Derived "<<m_m<<" is created."<<endl;
    }
private:
    int m_m;
};
int main()
{
    int a, b;
    cin>>a>>b;
    Base base(a);
    Derived derived(a, b);
    return 0;
}
