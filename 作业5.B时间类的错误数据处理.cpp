#include <iostream>
#include <iomanip>
using namespace std;
class Time
{
public:
    Time(int hour = 0, int minute = 0, int second = 0)
    {
        m_hour = hour;
        m_minute = minute;
        m_second = second;
    }
    Time(const Time &t)
    {
        m_hour = t.m_hour;
        m_minute = t.m_minute;
        m_second = t.m_second;
        cout<<"There was a call to the copy constructor : "<<m_hour<<","<<m_minute<<","<<m_second<<endl;
    }
    int hour()
    {
        return m_hour;
    }
    int minute()
    {
        return m_minute;
    }
    int second()
    {
        return m_minute;
    }
    void hour(int hour)
    {
        m_hour = hour;
    }
    void minute(int minute)
    {
        m_minute = minute;
    }
    void second(int second)
    {
        m_second = second;
    }
    Time& setTime(int hour, int minute, int second)
    {
        m_hour = hour;
        m_minute = minute;
        m_second = second;
        return *this;
    }
    Time& setTime(const Time &t)
    {
        m_hour = t.m_hour;
        m_minute = t.m_minute;
        m_second = t.m_second;
        return *this;
    }
    Time& getTime()
    {
        return *this;
    }
    Time& inputTime()//方法：按格式从标准输入读取数据修改Time对象的时分秒数值。该方法返回修改后的对象。
    {
        int hour, minute, second;
        cin>>hour>>minute>>second;
        m_hour = hour;
        m_minute = minute;
        m_second = second;
        return *this;
    }
    void showTime()//方法：输出“hh:mm:ss”，不足两位的要前面补0。如果对象不是合法的时间，则输出“Time error”。
    {
        if(m_hour >= 24 || m_minute >= 60 || m_second >= 60 || m_hour < 0 || m_minute < 0 || m_second < 0)
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
private:
    int m_hour;
    int m_minute;
    int m_second;
};
int main()
{
    Time t;
    int cases;
    cin>>cases;
    for(int i = 1; i <= cases; ++i)
    {
        if(i % 4 == 0)
        {
            int hour, minute, second;
            cin>>hour>>minute>>second;
            Time tt(hour, minute, second);
            tt.showTime();
        }
        if(i % 4 == 1)
        {
            int hour, minute, second;
            cin>>hour>>minute>>second;
            t.setTime(hour, minute, second).showTime();
        }
        if(i % 4 == 2)
            t.inputTime().showTime();
        if(i % 4 == 3)
        {
            int hour, minute, second;
            cin>>hour>>minute>>second;
            t.hour(hour);
            t.minute(minute);
            t.second(second);
            t.showTime();
        }
    }
}
