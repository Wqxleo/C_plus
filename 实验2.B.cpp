#include <iostream>
#include <iomanip>
using namespace std;
class Data
{
public:
    Data()
    {
        m_x = 0;
        cout<<"Data's default constructor."<<endl;
    }
    Data(int x)
    {
        m_x = x;
        cout<<"Data "<<m_x<<" is created."<<endl;
    }
    ~Data()
    {
        cout<<"Data "<<m_x<<" is erased."<<endl;
    }
    int getValue()
    {
        return m_x;
    }
    void setValue(int x)
    {
        m_x = x;
    }
private:
    int m_x;
};
class DataArray
{
public:
    DataArray()
    {
        cout<<"DataArray's default constructor."<<endl;
    }
    void setValues(int d[10])
    {
        int i;
        for(i = 0; i < 10; i++)
        {
            m_d[i].setValue(d[i]);
        }
    }
    int getSum()
    {
        int sum = 0;
        int i;
        for(i = 0; i < 10; i++)
        {
            sum += m_d[i].getValue();
        }
        return sum;
    }
    ~DataArray()
    {
        cout<<"DataArray's deconstructor."<<endl;
    }

private:
    Data m_d[10];
};

int main()
{
    DataArray dataArray;
    Data *aData;
    int data[10], tmp;
    int i;
    for (i = 0; i < 10; i++)
    {
        cin>>data[i];
    }
    dataArray.setValues(data);
    cout<<"Sum is "<<dataArray.getSum()<<endl;

    cin>>tmp;
    aData = new Data(tmp);
    cout<<"aData = "<<aData->getValue()<<endl;
    delete aData;
    return 0;
}
