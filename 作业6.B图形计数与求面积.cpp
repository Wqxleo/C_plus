#include <iostream>
#include <iomanip>
using namespace std;
class Shape
{
public:
   Shape()
   {
       cout<<"A shape is created!"<<endl;
       num++;
   }
   virtual ~Shape()
   {
       cout<<"A shape is erased!"<<endl;
    //  num--;
   }
   static int getNumOfShapes()
   {
       return num;
   }
   virtual double getArea()
   {

   }
private:
    static int num;
};
class Circle : public Shape
{
public:
    Circle(double r) : m_radious(r)
    {
        cout<<"A circle is created!"<<endl;
        num++;
    }
    ~Circle()
    {
        cout<<"A circle is erased!"<<endl;
       // num--;
    }
    double getArea()
    {
        return 3.14*m_radious*m_radious;
    }
    static int getNumOfCircles()
    {
        return num;
    }
private:
    static int num;
    double m_radious;
};
class Square : public Shape
{
public:
    Square(double a) : m_a(a)
    {
        cout<<"A square is created!"<<endl;
        num++;
    }
    ~Square()
    {
        cout<<"A square is erased!"<<endl;
    }
    double getArea()
    {
        return m_a*m_a;
    }
    static int getNumOfSquares()
    {
        return num;
    }
private:
    static int num;
    double m_a;
};
int Shape :: num = 0;
int Circle :: num = 0;
int Square :: num = 0;
int main()
{
    int cases;
    char type;
    double data;
    Shape *shape;
    cin>>cases;
    cout<<"numOfShapes = "<<Shape::getNumOfShapes();
    cout<<", numOfCircles = "<<Circle::getNumOfCircles();
    cout<<", numOfSquares = "<<Square::getNumOfSquares()<<endl;
    for (int i = 0; i < cases; i++)
    {
        cin>>type>>data;
        switch(type)
        {
        case 'C':
            shape = new Circle(data);
            break;
        case 'S':
            shape = new Square(data);
            break;
        }
        cout<<"Area = "<<setprecision(2)<<fixed<<shape->getArea()<<endl;
        delete shape;
    }
    cout<<"numOfShapes = "<<Shape::getNumOfShapes();
    cout<<", numOfCircles = "<<Circle::getNumOfCircles();
    cout<<", numOfSquares = "<<Square::getNumOfSquares()<<endl;
}

