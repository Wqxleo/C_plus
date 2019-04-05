#include <iostream>
#include <iomanip>
using namespace std;
class Time
{
public:
    Time()
    {

    }
    Time& inputTime()//方法：按格式从标准输入读取数据修改Time对象的时分秒数值。该方法返回修改后的对象。
    {
        flag = 0;
        int hour, minute, second;
        cin>>hour>>minute>>second;
        m_hour = hour;
        m_minute = minute;
        m_second = second;
        if(m_hour >= 24 || m_minute >= 60 || m_second >= 60 || m_hour < 0 || m_minute < 0 || m_second < 0)
        {
            flag = 1;
        }
        return *this;
    }
    Time(const Time &t)
    {
        m_hour = t.m_hour;
        m_minute = t.m_minute;
        m_second = t.m_second;
        flag = t.flag;
    }
    void showTime()
    {
       if(flag == 1)
        {
            cout<<"Time error"<<endl;
        }
        else
        {
            cout<<setw(2)<<setfill('0')<<m_hour<<":";

            cout<<setw(2)<<setfill('0')<<m_minute<<":";

            cout<<setw(2)<<setfill('0')<<m_second<<endl;
        }

    }
    Time& operator+=(int num)
    {
        int sum;
        sum = m_hour*3600 + m_minute*60 + m_second;
        sum += num;
        m_hour = sum/3600%24;
        m_minute = sum%3600/60;
        m_second = sum%60;
        return *this;
    }
    Time& operator-=(int num)
    {
        int sum;
        sum = m_hour*3600 + m_minute*60 + m_second;
        sum -= num;
        if(sum < 0)
            sum += 3600*24;
        m_hour = sum/3600%24;
        m_minute = sum%3600/60;
        m_second = sum%60;
        return *this;
    }
private:
    int m_hour;
    int m_minute;
    int m_second;
    int flag;
};
int main()
{
    int cases;
    cin>>cases;
    for(int i = 1; i <= cases; ++i)
    {
        Time t;
        t.inputTime();
        Time tt(t);
        int num;
        cin>>num;
        t += num;
        t.showTime();
        tt -= num;
        tt.showTime();
    }
}
