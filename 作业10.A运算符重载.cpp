#include <iostream>
#include <iomanip>
using namespace std;
template <typename T>
class Data
{
public:
    Data(T value = 0)
    {
        m_value = value;
    }
    ~Data()
    {

    }
    Data operator+(const Data<T> &another)
    {
        Data<T> tmp;
        tmp.m_value = m_value + another.m_value;
        return tmp;
    }
    bool operator>(const Data<T> &another)
    {
        if(m_value > another.m_value)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator<(const Data<T> &another)
    {
        if(m_value < another.m_value)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    friend ostream& operator<<(ostream&os, const Data<T>&data)
    {
        os<<fixed<<setprecision(2)<<data.m_value;
        return os;
    }
    void setValue(T value)
    {
        m_value = value;
    }

private:
    T m_value;

};
template <typename T>
class GetResult
{
public:
    static Data<T> getSum(Data<T> *arr, int num)
    {
        int i;
        Data<T> tmp;
        for(i = 0; i < num; i++)
        {
            tmp = tmp + arr[i];
        }
        return tmp;
    }
    static Data<T> getMax(Data<T> *arr, int num)
    {
        int i;
        Data<T> Max;
        Max = arr[0];
        for(i = 0; i < num; i++)
        {
            if(Max < arr[i])
            {
                Max = arr[i];
            }
        }
        return Max;
    }
    static Data<T> getMin(Data<T> *arr, int num)
    {
        int i;
        Data<T> Min;
        Min = arr[0];
        for(i = 1; i < num; i++)
        {
            if(Min > arr[i])
            {
                Min = arr[i];
            }
        }
        return Min;
    }
};
int main()
{
    Data<int> iData[1001];
    Data<double> dData[1001];
    int cases, num;
    char ch;
    int u;
    double v;
    Data<int> a(10), b(20);
    Data<double> c(3.14), d(-4.1);
    cout<<"a + b = "<<(a + b)<<endl;
    cout<<"max(a, b) = "<<(a > b ? a : b)<<endl;
    cout<<"min(a, b) = "<<(a < b ? a : b)<<endl;
    cout<<"c + d = "<<(c + d)<<endl;
    cout<<"max(c, d) = "<<(c > d ? c : d)<<endl;
    cout<<"min(c, d) = "<<(c < d ? c : d)<<endl;
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        cin>>ch;
        cin>>num;
        for (int j = 0; j < num; j++)
        {
            if (ch == 'i')
            {
                cin>>u;
                iData[j].setValue(u);
            }
            else if (ch == 'd')
            {
                cin>>v;
                dData[j].setValue(v);
            }
        }
        if (ch == 'i')
        {
            cout<<GetResult<int>::getMax(iData, num);
            cout<<" "<<GetResult<int>::getMin(iData, num);
            cout<<" "<<GetResult<int>::getSum(iData, num)<<endl;
        }
        else if (ch == 'd')
        {
            cout<<GetResult<double>::getMax(dData, num);
            cout<<" "<<GetResult<double>::getMin(dData, num);
            cout<<" "<<GetResult<double>::getSum(dData, num)<<endl;
        }
    }
    return 0;
}
