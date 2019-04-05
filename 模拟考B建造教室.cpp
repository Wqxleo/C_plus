#include <iostream>
using namespace std;
class Light
{
public:
    Light(int w)
    {
        m_w = w;
        cout<<"A "<<m_w<<"w light is created."<<endl;
    }
    ~Light()
    {
        cout<<"A "<<m_w<<"w light is erased."<<endl;
    }
private:
    int m_w;
};
class Chair
{
public:
    Chair(string c)
    {
        color = c;
        cout<<"A "<<color<<" chair is created."<<endl;
    }
    ~Chair()
    {
         cout<< "A "<<color<<" chair is created."<<endl;
    }
private:
    string color;
};
class ClassRoom
{
public:
    ClassRoom(int n1, int n2, int w, string c) : light(w),chair(c)
    {
        l_num = n1;
        c_num = n2;
        cout<<"A classroom having "<<l_num<<" lights and "<<c_num<<" chairs is created."<<endl;
    }
    ~ClassRoom()
    {
       cout<<"A classroom having "<<l_num<<" lights and "<<c_num<<" chairs is erased."<<endl;
    }
private:
    int c_num;
    int l_num;
    Light light;
    Chair chair;
};
int main()
{
    int nl, nc;
    int w;
    string color;
    cin>>w>>color;
    Light light(w);
    Chair chair(color);
    cin>>nl>>nc;
    cin>>w>>color;
    ClassRoom room(nl, nc, w, color);
    return 0;
}
