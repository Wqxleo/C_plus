#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class Point
{
public:
    Point(double x = 0, double y = 0)
    {
        m_x = x;
        m_y = y;
    }
    ~Point()
    {

    }
    Point(const Point &p)
    {
        m_x = p.m_x;
        m_y = p.m_y;
    }
    double getX() const
    {
        return m_x;
    }
    double getY() const
    {
        return m_y;
    }
private:
    double m_x;
    double m_y;
};
class Circle
{
public:
    Circle(Point o, double r) : m_o(o),m_r(r)
    {

    }
    ~Circle()
    {

    }
    Circle(const Circle &c)
    {
        m_o = c.m_o;
        m_r = c.m_r;
    }
    int JudgeRelation(const Circle &another)
    {
        double d,l;
        l = m_r-another.m_r;
        if(l < 0)
        {
            l = -l;
        }
        d = sqrt((m_o.getX()-another.m_o.getX())*(m_o.getX()-another.m_o.getX()) + (m_o.getY()-another.m_o.getY())*(m_o.getY()-another.m_o.getY()));
        if(d > m_r + another.m_r)
        {
            return 1;
        }
        else if(d == m_r+another.m_r)
        {
            return 3;
        }
        else if(d == l)
        {
            return 4;
        }
        else if(d < l)
        {
            return 2;
        }
        else
        {
            return 5;
        }
    }
private:
    Point m_o;
    double m_r;
};
int main()
{
    int cases;
    double x, y, r;
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        cin>>x>>y>>r;
        Point p1(x,y);
        Circle c1(p1, r);
        cin>>x>>y>>r;
        Point p2(x, y);
        Circle c2(p2, r);
        switch(c1.JudgeRelation(c2))
        {
        case 1:
            cout<<"Outside"<<endl;
            break;
        case 2:
            cout<<"Inside"<<endl;
            break;
        case 3:
            cout<<"Externally tangent"<<endl;
            break;
        case 4:
            cout<<"Internally tangent"<<endl;
            break;
        case 5:
            cout<<"Intersection"<<endl;
        }
    }
}
