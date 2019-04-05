#include <iostream>
#include <iomanip>
using namespace std;
class Data
{
public:
    void init(double d)
    {
        m_data = d;
    }
    double getValue()
    {
        return m_data;
    }
    void showValue()
    {
        cout<<m_data<<endl;
    }
private:
    double m_data;

};
int main()
{
    Data data;
    double d;
    cin>>d;
    data.init(d);
    cout<<data.getValue()<<endl;
    data.showValue();
}

