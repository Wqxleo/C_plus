#include <iostream>
#include <iomanip>
using namespace std;
class Point
{
public:
    Point(int x, int y)
    {
        m_x = x;
        m_y = y;
        numOfPoints++;
        cout<<"The Point ("<<m_x<<", "<<m_y<<") is created! Now, we have "<<numOfPoints<<" points."<<endl;
    }
    Point(const Point &p)
    {
        m_x = p.m_x;
        m_y = p.m_y;
        numOfPoints++;
        cout<<"A Point ("<<m_x<<", "<<m_y<<") is copied! Now, we have "<<numOfPoints<<" points."<<endl;
    }
    static int getNumOfPoints()
    {
        return numOfPoints;
    }
    int getX()
    {
        return m_x;
    }
    int getY()
    {
        return m_y;
    }
    ~Point()
    {
        numOfPoints--;
        cout<<"A Point ("<<m_x<<", "<<m_y<<") is erased! Now, we have "<<numOfPoints<<" points."<<endl;
    }
private:
    int m_x;
    int m_y;
    static int numOfPoints;
};
int Point :: numOfPoints = 0;
class Circle
{
public:
    Circle(int x, int y, int radius) : center(x, y),m_radius(radius)
    {
        numOfCircles++;
        cout<<"A circle at ("<<x<<", "<<y<<") and radius "<<radius<<" is created! Now, we have "<<numOfCircles<<" circles."<<endl;
    }
    Circle(const Point p, const int &r) : center(p)//const Point p把&去掉后，就不是引用，会调用一次拷贝构造函数。center(p)也会调用一次
    {
//        center.m_x = p.m_x;
//        center.m_y = p.m_y;
        m_radius = r;
        numOfCircles++;
        cout<<"A circle at ("<<center.getX()<<", "<<center.getY()<<") and radius "<<m_radius<<" is created! Now, we have "<<numOfCircles<<" circles."<<endl;
    }
    Point& getCenter()
    {
        return center;
    }
    bool pointInCircle(Point &p)
    {
        int flag;
        flag = (p.getX() - center.getX())*(p.getX() - center.getX()) + (p.getY() - center.getY())*(p.getY() - center.getY());
        if(flag < m_radius*m_radius)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    static int getNumOfCircles()
    {
        return numOfCircles;
    }
    ~Circle()
    {
        numOfCircles--;
        cout<<"A circle at ("<<center.getX()<<", "<<center.getY()<<") and radius "<<m_radius<<" is erased! Now, we have "<<numOfCircles<<" circles."<<endl;
    }
private:
    Point center;
    int m_radius;
    static int numOfCircles;
};
int Circle :: numOfCircles = 0;


int main()
{
    int cases,num;
    int x, y, r, px, py;
    Point aPoint(0,0), *bPoint;
    Circle aCircle(1,1,1);
    cin>>cases;
    cout<<"We have "<<Point::getNumOfPoints()<<" points and "<<Circle::getNumOfCircles()<<" circles now."<<endl;
    for (int i = 0; i < cases; i++)
    {
        cin>>x>>y>>r;
        bPoint = new Point(x,y);
        Circle circle(*bPoint, r);
        cin>>num;
        for (int j = 0; j < num; j++)
        {
            cin>>px>>py;
            if (circle.pointInCircle(*(new Point(px, py))))
            {
                cout<<"("<<px<<", "<<py<<") is in the circle at (";
                cout<<circle.getCenter().getX()<<", "<<circle.getCenter().getY()<<")."<<endl;
            }
            else
            {
                cout<<"("<<px<<", "<<py<<") is not in the circle at (";
                cout<<circle.getCenter().getX()<<", "<<circle.getCenter().getY()<<")."<<endl;
            }
        }
        delete bPoint;
    }
    cout<<"We have "<<Point::getNumOfPoints()<<" points, and "<<Circle::getNumOfCircles()<<" circles."<<endl;
    return 0;
}
