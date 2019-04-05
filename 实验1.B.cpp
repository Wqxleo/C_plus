#include <iostream>
#include <iomanip>
using namespace std;
class Data
{
public:
    Data(double data)
    {
        m_data = data;
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
    double d;
    cin>>d;
    Data data(d);
    cout<<data.getValue()<<endl;
    data.showValue();
}
