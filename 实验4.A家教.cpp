#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
    Person(string s1)
    {
        name = s1;
        cout<<"Person "<<name<<" is created."<<endl;
    }
    ~Person()
    {
        cout<<"Person "<<name<<" is erased."<<endl;
    }
protected:
    string name;
};
class Teacher : public Person
{
public:
    Teacher(string s1, string s3) : Person(s1)
    {
        job = s3;
        cout<<"Teacher "<<name<<" with position "<<job<<" is created."<<endl;
    }
    ~Teacher()
    {
        cout<<"Teacher "<<name<<" with position "<<job<<" is erased."<<endl;
    }
private:
    string job;
};

class Student : public Person
{
public:
    Student(string n, int i) : Person(n)
    {
        num = i;
        cout<<"Student "<<name<<" with id "<<num<<" is created."<<endl;
    }
    ~Student()
    {
       cout<<"Student "<<name<<" with id "<<num<<" is erased."<<endl;
    }
private:
    int num;
};

class Course
{
public:
    Course(string s1, string s2, string s3, string s4, int i) : m_s(s2, i), m_t(s2, s3)
    {
        name = s4;
        cout<<"Course "<<name<<" is created."<<endl;
    }
    ~Course()
    {
       cout<<"Course "<<name<<" is erased."<<endl;
    }
private:
   Teacher m_t;
   Student m_s;
   string name;
};
int main()
{
    string s1, s2, s3, s4;
    int i;
    cin>>s1>>s2>>s3>>s4>>i;
    Person person1(s1), person2(s2);
    Teacher teacher(s1, s3);
    Student student(s2, i);
    Course course(s1, s2, s3, s4, i);
    return 0;
}

