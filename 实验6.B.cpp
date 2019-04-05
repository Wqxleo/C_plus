#include <iostream>
#include <vector>
#include <math.h>
#include <iterator>
using namespace std;
class Point
{
public:
    Point(int x = 0, int y = 0)
    {
        m_x = x;
        m_y = y;

    }
    ~Point()
    {

    }
    void set(int x, int y)
    {
        m_x = x;
        m_y = y;
    }
    double operator-(const Point &p)
    {
        double a,b;
        a = (m_x - p.m_x)*(m_x - p.m_x);
        b = (m_y - p.m_y)*(m_y - p.m_y);
        return sqrt(a+b);
    }
private:
    double m_x;
    double m_y;
};
class PointArray
{
public:
    void append(const Point &p)
    {
        points.push_back(p);
    }
    double getMaxDis()
    {
        vector<Point> :: iterator itr1,itr2;
        double Max = 0;
        for(itr1 = points.begin(); itr1 != points.end(); itr1++)
        {
            for(itr2 = points.begin(); itr2 != points.end(); itr2++)
            {
                if(Max < *itr1 - *itr2)
                {
                    Max = *itr1 - *itr2;
                }
            }
        }
        return Max;
    }
private:
    vector<Point> points;
};
int main()
{
    Point p, p1(10, 10), p2(20, 20);
    PointArray pArr;
    double x, y;
    while(cin>>x>>y)
    {
        p.set(x, y);
        pArr.append(p);
    }
    cout<<p2 - p1<<endl;
    cout<<pArr.getMaxDis()<<endl;
    return 0;
}

