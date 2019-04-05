#include <iostream>
#include <iomanip>
using namespace std;
class Demo
{
public:
    Demo(int n = 0)
    {
        m_n = n;
        cout<<"A data "<<m_n<<" is created!"<<endl;
    }
    ~Demo()
    {
        cout<<"A data "<<m_n<<" is erased!"<<endl;
    }
    void show()
    {
        cout<<"This is data "<<m_n<<endl;
    }
private:
    int m_n;
};
int main()
{
    Demo tmp(10), tmp2;
    int d;
    cin>>d;
    Demo tmp3(d);

    tmp.show();
    tmp2.show();
    tmp3.show();
    return 0;
}
