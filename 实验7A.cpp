#include <iostream>
#include <cstring>
#include <cmath>
#include <sstream>
#include <string>
using namespace std;
class Decimal
{
public:
    Decimal(string s = "0")
    {
        str = s;
        len = str.size();
    }
    Decimal(int a)
    {
        stringstream ss;
        ss<<a;
        ss>>str;
        len = str.size();
    }
    Decimal(const Decimal &d)
    {
        str = d.str;
        len = d.len;
    }
    int getLength()
    {
        return len;
    }
    Decimal operator+(const Decimal &d)
    {
        int flag2,Max,Min;
        Decimal tmp;
        if(len > d.len)
        {
            Max = len;
            Min = d.len;
            tmp = *this;
            flag2 = 0;
        }
        else
        {
            Max = d.len;
            Min = len;
            tmp = d;
            flag2 = 1;
        }
//        cout<<"flag2 = "<<flag2<<endl;
        int i,j,k;
        k = tmp.len-1;

        int a;
        int flag = 0;
        if(flag2 = 0)
        {
            for(i = len-1,j = d.len-1; i >= 0; i--,j--)
            {
                if(j >= 0)
                {
                    a = (str[i]-'0') + (d.str[i]-'0') + flag;
                    flag = 0;

                }
                else
                {
                    a = (str[i]-'0') + flag;
                    flag = 0;
                }
                if(a > 9 && i != 0)
                {
                    a -= 10;
                    tmp.str[k] = a + '0';
                    flag = 1;
                }
                else if(i == 0 && a >9)
                {
                    a -= 10;
                    tmp.str[k] = a + '0';
                    tmp.str.insert(0,"1");
                }
                else
                {
                    tmp.str[k] = a + '0';
                    flag = 0;
                }
                k--;

            }
        }
        else
        {
            for(i = len-1,j = d.len-1; j >= 0; i--,j--)
            {
                if(i >= 0)
                {
                    a = (str[i]-'0') + (d.str[i]-'0') + flag;
                    flag = 0;
                }
                else
                {
                    a = (d.str[i]-'0') + flag;
                    flag = 0;
                }
//                cout<<"a = "<<a<<endl;
                if(a > 9 && i != 0)
                {
                    a -= 10;
                    tmp.str[k] = a + '0';
                    flag = 1;
//                    cout<<tmp.str[k]<<endl;
                }
                else if(i == 0 && a >9)
                {
                    a -= 10;
                    tmp.str[k] = a + '0';
                    tmp.str.insert(0,"1");
                }
                else
                {
                    tmp.str[k] = a + '0';
                    flag = 0;
                }
                k--;

            }
        }
//        cout<<"加法可实现"<<endl;
//        cout<<tmp<<" ";
        return tmp;
    }
    Decimal operator+(int n)
    {
        stringstream ss;
        Decimal tmp;
        ss<<n;
        ss>>tmp.str;
        return *this + tmp;
    }
    Decimal& operator++()
    {
        *this = *this +1;
        return *this;
    }
    friend istream& operator>>(istream &is, Decimal &d);
    friend ostream& operator<<(ostream &os, const Decimal &d);
    char operator[](int i)
    {
        return str[i];
    }
private:
    string str;
    int len;

};
istream& operator>>(istream &is, Decimal &d)
{
    is>>d.str;
    d.len = d.str.size();
    return is;
}
ostream& operator<<(ostream &os, const Decimal &d)
{
    os<<d.str;
    return os;
}
int main()
{
    Decimal a, b, c, d, e, f("554433"), g(12345);
    int i;
    cin>>a>>b>>i;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"i = "<<i<<endl;
    c = a + b;
    d = ++a;
    e = b + i;
    cout<<"a = "<<a<<endl;
    cout<<"c = "<<c<<endl;
    cout<<"d = "<<d<<endl;
    cout<<"e = "<<e<<endl;
    cout<<"f = "<<f<<endl;
    cout<<"g = "<<g<<endl;

    cout<<c[0];
    for (i = 1; i < c.getLength(); i++)
    {
        cout<<" "<<c[i];
    }
    cout<<endl;
    return 0;
}
