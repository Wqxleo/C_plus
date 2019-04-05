#include <iostream>
using namespace std;
class Vector
{
public:
    Vector(int x = 0, int y = 0, int z = 0)
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }
    ~Vector()
    {

    }
    Vector(const Vector &v)
    {
        m_x = v.m_x;
        m_y = v.m_y;
        m_z = v.m_z;
    }
    Vector operator+(const Vector &v)
    {
        Vector tmp;
        tmp.m_x = m_x + v.m_x;
        tmp.m_y = m_y + v.m_y;
        tmp.m_z = m_z + v.m_z;
        return tmp;
    }
    Vector operator-(const Vector &v)
    {
        Vector tmp;
        tmp.m_x = m_x - v.m_x;
        tmp.m_y = m_y - v.m_y;
        tmp.m_z = m_z - v.m_z;
        return tmp;
    }
    Vector operator*(int a)
    {
        Vector tmp;
        tmp.m_x = m_x*a;
        tmp.m_y = m_y*a;
        tmp.m_z = m_z*a;
        return tmp;
    }
    Vector operator*(const Vector &v)
    {
        Vector tmp;
        tmp.m_x = m_y*v.m_z - m_z*v.m_y;
        tmp.m_y = m_z*v.m_x - m_x*v.m_z;
        tmp.m_z = m_x*v.m_y - m_y*v.m_x;
        return tmp;
    }
//    void operator=(Vector &v)
//    {
//        m_x = v.m_x;
//        m_y = v.m_y;
//        m_z = v.m_z;
//    }
    friend istream& operator>>(istream& is, Vector &v);
    friend ostream& operator<<(ostream& os, Vector &v);
private:
    int m_x;
    int m_y;
    int m_z;
};
istream& operator>>(istream& is, Vector &v)
{
    is>>v.m_x>>v.m_y>>v.m_z;
    return is;
}
ostream& operator<<(ostream& os, Vector &v)
{
    if(v.m_x == 0 && v.m_y == 0 && v.m_z == 0)
    {
        os<<0;
    }
    else
    {
        if(v.m_x != 0)
        {
            os<<v.m_x<<"i";
        }

        if(v.m_y > 0)
        {
            if(v.m_x != 0)
            os<<"+"<<v.m_y<<"j";
            else if(v.m_x == 0)
            os<<v.m_y<<"j";
        }
        else if(v.m_y < 0)
        {
            os<<v.m_y<<"j";
        }

        if(v.m_z > 0)
        {
            if(v.m_y == 0 && v.m_x == 0)
            os<<v.m_z<<"k";
            else
            os<<"+"<<v.m_z<<"k";


        }
        else if(v.m_z < 0)
        {
            os<<v.m_z<<"k";
        }
    }
    return os;
}

int main()
{
    Vector vec1, vec2, vec3;
    int cases, n;
    cin>>cases;
    cout<<"vect+vec2\tn*vec1\tvec1*vec2\n";
    for (int i = 0; i < cases; i++)
    {
        cin>>vec1>>vec2>>n;
        vec3 = vec1 + vec2;
        cout<<vec3<<"\t";
        vec3 = vec1 * n;
        cout<<vec3<<"\t";
        vec3 = vec1 * vec2;
        cout<<vec3<<endl;
    }
    return 0;
}
