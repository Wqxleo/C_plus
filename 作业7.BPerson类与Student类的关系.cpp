#include <iostream>
using namespace std;
class Person
{
public:
    Person(string n, int age)
    {
        m_name = n;
        m_age = age;
        cout<<"A person "<<m_name<<" whose age is "<<m_age<<" is created."<<endl;
    }
    ~Person()
    {
        cout<<"A person "<<m_name<<" whose age is "<<m_age<<" is erased."<<endl;
    }
    void show()
    {
        cout<<"Name is "<<m_name<<" and age is "<<m_age<<"."<<endl;
    }
protected:
    string m_name;
    int m_age;

};
class Student : public Person
{
public:
    Student(string n, int a, int g) : Person(n,a),m_grade(g)
    {
        cout<<"A student whose grade is "<<m_grade<<" is created."<<endl;
    }
    ~Student()
    {
        cout<<"A student whose grade is "<<m_grade<<" is erased."<<endl;
    }
    void show()
    {
        cout<<"Grade is "<<m_grade<<"."<<endl;
    }
private:
    int m_grade;
};
int main()
{
    string n;
    int a, g;
    cin>>n>>a>>g;
    Student student(n, a, g);
    student.Person::show();
    student.show();
    return 0;
}
