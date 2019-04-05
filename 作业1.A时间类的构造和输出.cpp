#include <iostream>
#include <iomanip>
using namespace std;
class Time
{
public:
    Time(int, int, int);
    void showTime()
    {
        cout<<setw(2)<<setfill('0')<<m_hour<<":";

        cout<<setw(2)<<setfill('0')<<m_minute<<":";

        cout<<setw(2)<<setfill('0')<<m_second<<endl;
    }

private:
int m_hour, m_minute, m_second;
};
Time::Time(int hour, int minute, int second)
{
    m_hour = hour;
    m_minute = minute;
    m_second = second;
}
int main()
{
    int cases;
    cin>>cases;
    for(int i = 1; i <= cases; ++i)
    {
        int hour, minute, second;
        cin>>hour>>minute>>second;
        Time t(hour, minute, second);
        t.showTime();
    }
}
