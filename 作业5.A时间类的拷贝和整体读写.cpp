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
    void showTime()
    {
        cout<<setw(2)<<setfill('0')<<m_hour<<":";

        cout<<setw(2)<<setfill('0')<<m_minute<<":";

        cout<<setw(2)<<setfill('0')<<m_second<<endl;
    }
private:
    int m_hour;
    int m_minute;
    int m_second;
};
int main()
{
    cout<<"Copy constructor test output :"<<endl;
    Time t;
    Time tt(t);
    Time ttt(1, 2, 3);
    Time tttt(ttt.getTime());
    cout<<"\nTest data output :"<<endl;

    int cases;
    cin>>cases;
    for(int i = 1; i <= cases; ++i)
    {
        if(i % 2 == 0)
        {
            int hour, minute, second;
            cin>>hour>>minute>>second;
            t.setTime(hour, minute, second).showTime();
        }
        if(i % 2 == 1)
        {
            int hour, minute, second;
            cin>>hour>>minute>>second;
            Time tt(hour, minute, second);
            t.setTime(tt).showTime();
        }
    }
}
