
int main()
{
    char c;
    int num, i;#include <iostream>
#include <iomanip>
using namespace std;
class Point
{
public:
    Point(double x = 0, double y = 0)
    {
        m_x = x;
        m_y = y;
        cout<<"Point : ("<<m_x<<", "<<m_y<<") is created."<<endl;
    }
    Point(const Point &an)
    {
        m_x = an.m_x;
        m_y = an.m_y;
        cout<<"Point : ("<<m_x<<", "<<m_y<<") is copied."<<endl;
    }
    double getX()
    {
        return m_x;
    }
    double getY()
    {
        return m_y;
    }
    void show(void)
    {
        cout<<"Point : ("<<m_x<<", "<<m_y<<")"<<endl;
    }

    ~Point()
    {
        cout<<"Point : ("<<m_x<<", "<<m_y<<") is erased."<<endl;
    }
private:
    double m_x;
    double m_y;

};
class Line
{
public:
    Line(double x1, double y1, double x2, double y2) : m_s(x1,y1),m_e(x2,y2)
    {
        cout<<"Line : ("<<x1<<", "<<y1<<") to ("<<x2<<", "<<y2<<") is created."<<endl;
    }
    Line(const Point &p1, const Point &p2) : m_s(p1),m_e(p2)
    {
        cout<<"Line : ("<<m_s.getX()<<", "<<m_s.getY()<<") to ("<<m_e.getX()<<", "<<m_e.getY()<<") is created."<<endl;
    }
    void show()
    {
        cout<<"Line : ("<<m_s.getX()<<", "<<m_s.getY()<<") to ("<<m_e.getX()<<", "<<m_e.getY()<<")"<<endl;
    }
    ~Line()
    {
        cout<<"Line : ("<<m_s.getX()<<", "<<m_s.getY()<<") to ("<<m_e.getX()<<", "<<m_e.getY()<<") is erased."<<endl;
    }
private:
   Point m_s;
   Point m_e;

};
    double x1, x2, y1, y2;
    Point p(1, -2), q(2, -1), t;
    t.show();
    std::cin>>num;
    for(i = 1; i <= num; i++)
    {
        std::cout<<"=========================\n";
        std::cin>>x1>>c>>y1>>x2>>c>>y2;
        Line line(x1, y1, x2, y2);
        line.show();
    }
    std::cout<<"=========================\n";
    Line l1(p, q), l2(p, t), l3(q, t), l4(t, q);
    l1.show();
    l2.show();
    l3.show();
    l4.show();
}
