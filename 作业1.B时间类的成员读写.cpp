#include <iostream>
#include <iomanip>
using namespace std;
class Time
{
public:
    void hour(int h)
    {
        m_hour = h;
    }
    void minute(int m)
    {
        m_minute = m;
    }
    void second(int s)
    {
        m_second = s;
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
        return m_second;
    }

private:
   int m_hour, m_minute, m_second;
};
int main()
{
    Time t;
    int cases;
    cin>>cases;
    for(int i = 1; i <= cases; ++i)
    {
        int hour, minute, second;
        cin>>hour>>minute>>second;
        t.hour(hour);
        t.minute(minute);
        t.second(second);
        cout<<setw(2)<<setfill('0')<<t.hour()<<":";
        cout<<setw(2)<<setfill('0')<<t.minute()<<":";
        cout<<setw(2)<<setfill('0')<<t.second()<<endl;
    }
}
