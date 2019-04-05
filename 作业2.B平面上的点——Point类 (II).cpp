#include <iostream>
#include <iomanip>
using namespace std;
class Point
{
public:
    Point(const Point &p);
    Point()
    {
        m_x = 0;
        m_y = 0;
        cout<<"Point : ("<<setprecision(16)<<m_x<<","<<" "<<setprecision(16)<<m_y<<")"<<" is created."<<endl;
    }
    Point(double a)
    {
        m_x = a;
        m_y = a;
        cout<<"Point : ("<<setprecision(16)<<m_x<<","<<" "<<setprecision(16)<<m_y<<")"<<" is created."<<endl;
    }
    Point(double a, double b)
    {
        m_x = a;
        m_y = b;
        cout<<"Point : ("<<setprecision(16)<<m_x<<","<<" "<<setprecision(16)<<m_y<<")"<<" is created."<<endl;
    }
    void show()
    {
        cout<<"Point : ("<<setprecision(16)<<m_x<<","<<" "<<setprecision(16)<<m_y<<")"<<endl;
    }

    ~Point()
    {
        cout<<"Point : ("<<setprecision(16)<<m_x<<","<<" "<<setprecision(16)<<m_y<<")"<<" is erased."<<endl;
    }
private:
    double m_x,m_y;
};
Point::Point(const Point &p)
{
    m_x = p.m_x;
    m_y = p.m_y;
    cout<<"Point : ("<<setprecision(16)<<m_x<<","<<" "<<setprecision(16)<<m_y<<")"<<" is copied."<<endl;
}
int main()
{
    char c;
    double a, b;
    Point q;
    while(std::cin>>a>>c>>b)
    {
        Point p(a, b);
        p.show();
    }
    Point q1(q), q2(1);
    q1.show();
    q2.show();
    q.show();
}
