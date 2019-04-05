#include <iostream>
#include <iomanip>
using namespace std;
class Point
{
public:
    Point(double x = 0, double y = 0)
    {
        m_x = x;
        m_y = y;
        cout<<"The Point ("<<setprecision(2)<<fixed<<m_x<<", "<<setprecision(2)<<fixed<<m_y<<") is created!"<<endl;
    }
    Point(const Point &p) : m_x(p.m_x), m_y(p.m_y)
    {
        cout<<"A Point ("<<setprecision(2)<<fixed<<m_x<<", "<<setprecision(2)<<fixed<<m_y<<") is copied!"<<endl;
    }
    double getX()
    {
        return m_x;
    }
    double getY()
    {
        return m_y;
    }
    void setX(double x)
    {
        m_x = x;
    }
    void setY(double y)
    {
        m_y = y;
    }
    ~Point()
    {
        cout<<"A Point ("<<setprecision(2)<<fixed<<m_x<<", "<<setprecision(2)<<fixed<<m_y<<") is erased!"<<endl;
    }
private:
    double m_x;
    double m_y;
};
class Graph
{
public:
    Graph():points(NULL),numOfPoints(0)
    {
        cout<<"A graph with "<<numOfPoints<<" points is created!"<<endl;
    }
    Graph(const Point *p, int num)
    {
        int i;
        numOfPoints = num;
        points = new Point[numOfPoints];
        for(i = 0; i < num; i++)
        {
            points[i] = p[i];//注意：同一类的对象之间的赋值运算（=）不调用拷贝构造函数。
        }
        cout<<"A graph with "<<numOfPoints<<" points is created!"<<endl;
    }
    Point getCentroid()
    {
        int i;
        double x = 0,y = 0;
        for(i = 0; i < numOfPoints; i++)
        {
            x += points[i].getX();
            y += points[i].getY();
        }
        x = x/numOfPoints;
        y = y/numOfPoints;
        /*当使用对象作为函数返回值时，会产生一个临时对象，此时会调用拷贝构造函数。
        但是在g++编译器（也就是大家常用的code::blocks所用的编译器）中，当函数返回
        的对象给另一个对象进行赋值时，如果函数返回值是一个局部变量，则不会调用拷贝
        构造函数。所以，如果想在此程序中实现拷贝构造函数的调用，必须在getCentroid
        中返回一个使用new运算符创建的对象，而不是一个已经定义的局部对象。*/
        Point *p=new Point(x,y);
        return *p;
    }
    ~Graph()
    {
        delete []points;
        //delete point;
        cout<<"A graph with "<<numOfPoints<<" points is erased!"<<endl;
    }
private:
    Point *points;
    int numOfPoints;
};
int main()
{
    int cases,num;
    double x, y;
    Point centroid;
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        cin>>num;
        Point points[num];
        for (int j = 0; j < num; j++)
        {
            cin>>x>>y;
            points[j] = *(new Point(x, y));
        }
        Graph graph(points, num);
        centroid = graph.getCentroid();
        cout<<setprecision(2)<<fixed<<"The centroid is ("<<centroid.getX()<<", "<<centroid.getY()<<")."<<endl;
    }
    return 0;
}




//
//
//#include <iostream>
//#include <iomanip>
//using namespace std;
//class Point
//{
//private:
//    double x,y;
//public:
//    Point():x(0),y(0)
//    {
//        cout<<"The Point ("<<setprecision(2)<<fixed<<x<<", "<<setprecision(2)<<fixed<<y<<") is created!"<<endl;
//    }
//    Point(double a, double b):x(a),y(b)
//    {
//        cout<<"The Point ("<<setprecision(2)<<fixed<<x<<", "<<setprecision(2)<<fixed<<y<<") is created!"<<endl;
//    }
//    Point(const Point& p ):x(p.x),y(p.y)
//    {
//        cout<<"A Point ("<<setprecision(2)<<fixed<<x<<", "<<setprecision(2)<<fixed<<y<<") is copied!"<<endl;
//    }
//    ~Point()
//    {
//        cout<<"A Point ("<<setprecision(2)<<fixed<<x<<", "<<setprecision(2)<<fixed<<y<<") is erased!"<<endl;
//    }
//    double getX()
//    {
//        return x;
//    }
//    double getY()
//    {
//        return y;
//    }
//    void setX(double a)
//    {
//        x=a;
//    }
//    void setY(double a)
//    {
//        y=a;
//    }
//};
//class Graph
//{
//private:
//    Point *points;
//    int numOfPoints;
//public:
//    Graph():points(NULL),numOfPoints(0)
//    {
//        cout<<"A graph with "<<numOfPoints<<" points is created!"<<endl;
//    }
//    Graph(Point *p,int a)
//    {
//        points=new Point[a];
//        for(int i=0; i<a; i++)
//        {
//            points[i]=p[i];
//        }
//        numOfPoints=a;
//        cout<<"A graph with "<<numOfPoints<<" points is created!"<<endl;
//    }
//    ~Graph()
//    {
//        delete []points;
//        cout<<"A graph with "<<numOfPoints<<" points is erased!"<<endl;
//    }
//    Point getCentroid()
//    {
//        int i;
//        double m=0,n=0;
//        for(i=0; i<numOfPoints; i++)
//        {
//            m+=points[i].getX();
//            n+=points[i].getY();
//        }
//        m=m/numOfPoints;
//        n=n/numOfPoints;
//        Point *p=new Point(m,n);
//        return *p;
//    }
//};
//int main()
//{
//    int cases,num;
//    double x, y;
//    Point centroid;
//    cin>>cases;
//    for (int i = 0; i < cases; i++)
//    {
//        cin>>num;
//        Point points[num];
//        for (int j = 0; j < num; j++)
//        {
//            cin>>x>>y;
//            points[j] = *(new Point(x, y));
//        }
//        Graph graph(points, num);
//        centroid = graph.getCentroid();
//        cout<<setprecision(2)<<fixed<<"The centroid is ("<<centroid.getX()<<", "<<centroid.getY()<<")."<<endl;
//    }
//    return 0;
//}
//
