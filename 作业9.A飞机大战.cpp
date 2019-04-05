#include <iostream>
using namespace std;
class FlyThing
{
public:
    FlyThing(string name, int x, int y)
    {
        m_name = name;
        m_x = x;
        m_y = y;
    }
    ~FlyThing()
    {

    }
    virtual void fly() = 0;
    void show()
    {
        cout<<m_name<<" at "<<m_x<<" "<<m_y<<endl;
    }
protected:
    string m_name;
    int m_x;
    int m_y;

};
class EnemyPlane : public FlyThing
{
public:
    EnemyPlane(string name, int x,int y) : FlyThing(name, x, y)
    {

    }
    ~EnemyPlane()
    {

    }
    void fly()
    {
        m_y++;
    }
private:

};
class MyPlane : public FlyThing
{
public:
    MyPlane(string name, int x,int y) : FlyThing(name, x, y)
    {

    }
    ~MyPlane()
    {

    }
    void fly()
    {
        char c;
        cin>>c;
        switch(c)
        {
        case 'a':
        case 'A':
            m_x--;
            break;
        case 'd':
        case 'D':
            m_x++;
            break;
        case 'w':
        case 'W':
            m_y--;
            break;
        case 's':
        case 'S':
            m_y++;
            break;
        }
    }
private:

};
int main()
{
    FlyThing **planes;
    int numOfEnemplanes, i, x, y, numOfMoves, j;
    string str;
    cin>>numOfEnemplanes;
    planes = new FlyThing*[numOfEnemplanes + 1];
    planes[0] = new MyPlane("WUDI", 50, 50);
    for(i = 1; i <= numOfEnemplanes; i++)
    {
        cin>>str>>x>>y;
        planes[i] = new EnemyPlane(str, x, y);
    }

    for (j = 0; j < numOfEnemplanes + 1; j++)
    {
        planes[j]->show();
    }

    cin>>numOfMoves;
    for (i = 0; i < numOfMoves; i++)
    {
        for (j = 0; j < numOfEnemplanes + 1; j++)
        {
            planes[j]->fly();
            planes[j]->show();
        }
    }
    return 0;
}

