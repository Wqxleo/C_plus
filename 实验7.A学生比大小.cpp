#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
    Student(int age = 0, string name = "A")
    {
        m_age = age;
        m_name = name;
    }
    friend istream& operator>>(istream &is,Student &stu);
    friend ostream& operator<<(ostream &os,Student &stu);
    ~Student()
    {

    }
    bool operator>(Student &stu)
    {
        if(m_age > stu.m_age)
        {
            return true;
        }
        else if(m_age < stu.m_age)
        {
            return false;
        }
        else
        {
            if(m_name>stu.m_name)
                return true;
            else
                return false;
        }
    }
private:
    int m_age;
    string m_name;
};
istream& operator>>(istream &is,Student &stu)
{
    is>>stu.m_name>>stu.m_age;
    return is;
}
ostream& operator<<(ostream &os,Student &stu)
{
    os<<stu.m_name<<" "<<stu.m_age;
    return os;
}
int main()
{
    Student stu, max;
    while(cin>>stu)
    {
        if (stu > max)
            max = stu;
        //cout<<max<<endl;
    }
    cout<<max<<endl;
    return 0;
}
