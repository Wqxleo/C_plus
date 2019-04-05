#include <stdio.h>
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
    DataArray(int n, int *tmp)
    {
        int i;
        m_n = n;
        data = new Data[m_n];//申请动态内存
        for(i = 0; i < m_n; i++)
        {
            data[i].setValue(tmp[i]);
        }
        cout<<"DataArray's constructor."<<endl;
    }
    int getSum()
    {
        int sum = 0;
        int i;
        for(i = 0; i < m_n; i++)
        {
            sum += data[i].getValue();
        }
        return sum;
    }
    ~DataArray()
    {
        delete []data;//释放数组指针
        cout<<"DataArray's deconstructor."<<endl;
    }

private:
    int m_n;
    Data *data;
};

int main()
{
    freopen("out.txt","w",stdout);
    int i, n;
    Data test, *testP;
    cin>>n;
    int tmp[n];
    for (i = 0; i < n; i++)
        cin>>tmp[i];
    DataArray datas(n, tmp);
    cout<<"Sum is "<<datas.getSum()<<endl;
    testP = new Data;
    cin>>n;
    testP->setValue(n);
    delete testP;
    return 0;
}
