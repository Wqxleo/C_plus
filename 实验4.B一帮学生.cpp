#include <iostream>
using namespace std;
class Date
{
public:
    Date(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
        cout<<"Date "<<year<<"-"<<month<<"-"<<day<<" is created."<<endl;
    }
    int getYear()
    {
        return year;
    }
    int getMonth()
    {
        return month;
    }
    int getDay()
    {
        return day;
    }
    ~Date()
    {
        cout<<"Date "<<year<<"-"<<month<<"-"<<day<<" is erased."<<endl;
    }
private:
    int year;
    int month;
    int day;
};
class Person
{
public:
    Person(int y, int m, int d, string n) : birthday(y,m,d),name(n)
    {

        numOfPersons++;
        cout<<"The "<<numOfPersons<<"th person "<<name<<" whose birthday is "<<y<<"-"<<m<<"-"<<d<<" is created."<<endl;
    }
    ~Person()
    {
       cout<<"Person "<<name<<" whose birthday is "<<birthday.getYear()<<"-"<<birthday.getMonth()<<"-"<<birthday.getDay()<<" is erased."<<endl;
    }
protected:
    Date birthday;
    string name;
private:
    static int numOfPersons;
};
class Student : public Person
{
public:
    Student(int y, int m, int d, string n, int i) : Person(y,m,d,n),id(i)
    {
        numOfStudents++;
        cout<<"The "<<numOfStudents<<"th student "<<name<<" whose birthday is "<<y<<"-"<<m<<"-"<<d<<" and id is "<<id<<" is created."<<endl;
    }
    ~Student()
    {
        cout<<"Student "<<name<<" whose birthday is "<<birthday.getYear()<<"-"<<birthday.getMonth()<<"-"<<birthday.getDay()<<" and id is "<<id<<" is erased."<<endl;
    }
private:
    int id;
    static int numOfStudents;
};
int Person :: numOfPersons = 0;
int Student :: numOfStudents = 0;
int main()
{
    int year, month, day, id, i;
    string name;
    int num;
    cin>>num;
    Student **students = new Student*[num];
    for (i = 0; i < num; i++)
    {
        cin>>year>>month>>day>>id>>name;
        students[i] = new Student(year, month, day, name, id);
    }
    for (i = 0;i <num; i++)
        delete students[i];
    delete[] students;
    return 0;
}

