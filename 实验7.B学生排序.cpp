#include <iostream>
#include <string>
#include <vector>
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
    bool operator<(Student &stu)
    {
        return !(*this > stu);
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

class StudentGroup
{
public:
    void add(const Student &stu)
    {
        students.push_back(stu);
    }
    void srt()
    {
        int i,j;
        Student tmp;
        for(i = 1; i < students.size(); i++)
        {
            for(j = 0; j < students.size()-i; j++)
            {
                if(students[j] > students[j+1])
                {
                    tmp = students[j+1];
                    students[j+1] = students[j];
                    students[j] = tmp;
                }
            }
        }
    }
    void show()
    {
        int i;
        for(i = 0; i < students.size(); i++)
            cout<<students[i]<<endl;
    }
private:
    vector<Student> students;
};
int main()
{
    Student stu, max;
    StudentGroup stuG;
    while(cin>>stu)
    {
        if (!(stu < max))
            max = stu;
        stuG.add(stu);
    }
    stuG.srt();
    stuG.show();
    cout<<"The max is "<<max<<endl;
    return 0;
}
