#include <iostream>
#include <iomanip>
using namespace std;
class Point
{
public:
    Point(double a, double b)
    {
        m_x = a;
        m_y = b;
    }
    Point()
    {
        m_x = 0;
        m_y = 0;
    }
    void show()
    {
        cout<<"Point : ("<<setprecision(16)<<m_x<<","<<" "<<setprecision(16)<<m_y<<")"<<endl;
    }
private:
    double m_x;
    double m_y;

};
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
    q.show();
}

