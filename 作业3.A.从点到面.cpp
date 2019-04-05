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
        cout<<"A point ("<<m_x<<", "<<m_y<<") is created!"<<endl;
    }
    int getX()
    {
        return m_x;
    }
    int getY()
    {
        return m_y;
    }
    Point(const Point &another)
    {
        m_x = another.m_x;
        m_y = another.m_y;
        cout<<"A point ("<<m_x<<", "<<m_y<<") is copied!"<<endl;
    }
    ~Point()
    {
        cout<<"A point ("<<m_x<<", "<<m_y<<") is erased!"<<endl;
    }
private:
    int m_x;
    int m_y;

};
class Rectangle
{
public:
    Rectangle(int l_x, int l_y, int r_x, int r_y) : m_leftTop(l_x,l_y), m_rightBottom(r_x, r_y)
    {
        cout<<"A rectangle ("<<l_x<<", "<<l_y<<") to ("<<r_x<<", "<<r_y<<") is created!"<<endl;
    }
    Point& getLeftTop()//加上&之后返回对象本身，不会调用拷贝构造函数
    {
       return m_leftTop;
    }
    Point getRightBottome()
    {
        return m_rightBottom;
    }
    Rectangle (const Rectangle &another) : m_leftTop(another.m_leftTop), m_rightBottom(another.m_rightBottom)
    {

    }

    int  getArea()
    {
       return  (m_leftTop.getY()-m_rightBottom.getY())*(m_rightBottom.getX()-m_leftTop.getX());
    }
    ~Rectangle()
    {
        cout<<"A rectangle ("<<m_leftTop.getX()<<", "<<m_leftTop.getY()<<") to ("<<m_rightBottom.getX()<<", "<<m_rightBottom.getY()<<") is erased!"<<endl;
    }
private:
    Point m_leftTop;
    Point m_rightBottom;

};
int main()
{
    int cases;
    int x1, y1, x2, y2;

    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        cin>>x1>>y1>>x2>>y2;
        Rectangle rect(x1,y1,x2,y2);
        cout<<"Area: "<<rect.getArea()<<endl;
        cout<<"Left top is ("<<rect.getLeftTop().getX()<<", "<<rect.getLeftTop().getY()<<")"<<endl;
        cout<<"Right bottom is ("<<rect.getRightBottome().getX()<<", "<<rect.getRightBottome().getY()<<")"<<endl;
    }
    return 0;
}
