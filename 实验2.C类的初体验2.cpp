#include<iostream>
#include<iomanip>
using namespace std;
class Data
{
public:
    Data()
    {
        m_data = 0;
        cout<<"Data's default constructor."<<endl;
    }
    Data(int data)
    {
        m_data = data;
        cout<<"Data "<<m_data<<" is created."<<endl;
    }
    ~Data()
    {
        cout<<"Data "<<m_data<<" is erased."<<endl;
    }
    int getValue()
    {
        return m_data;
    }
    void setValue(int data)
    {
        m_data = data;
    }

private:
    int m_data;
};
class DataArray()
int main()
{
    DataArray dataArray;
    Data *aData;
    int data[10], tmp;
    int i;
    for (i = 0; i < 10; i++){
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
