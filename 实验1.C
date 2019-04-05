#include <iostream>
#include <iomanip>
using namespace std;
class Data
{
public:
    Data(double data = 0)
    {
        m_data = data;
        cout<<"Initialize a data"<<" "<<m_data<<endl;
    }
//    Data(double data)
//    {
//        m_data = data;
//        cout<<"Initialize a data"<<" "<<m_data<<endl;
//    }
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
    Data data1;
    double d;
    cin>>d;
    Data data(d);
    cout<<data.getValue()<<endl;
    data.showValue();
}
