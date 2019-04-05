#include <iostream>
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
    friend ostream& operator<<(ostream& ,const Point &);
private:
   int m_x;
   int m_y;

};
ostream& operator<<(ostream&os,const Point &p)
{
    os<<p.m_x<<" "<<p.m_y;
    return os;
}
template <typename T>
class Data
{
public:
    Data(T data)
    {
        m_data = data;
    }
    ~Data()
    {

    }
    void show()
    {
        cout<<m_data<<endl;
    }
private:
    T m_data;
};
int main()
{
    string n;
    int x, y, d;
    char c;
    cin>>n;
    cin>>x>>y>>d;
    cin>>c;
    Point p(x, y);
    Data<char> aChar(c);
    Data<int> anInt(d);
    Data<Point> aPoint(p);
    Data<string> aString(n);
    aChar.show();
    anInt.show();
    aString.show();
    aPoint.show();
    return 0;
}
