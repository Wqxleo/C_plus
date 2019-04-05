#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
class Person
{
public:
    Person(char str[], int age)
    {
        name = new char[strlen(str) + 1];
        strcpy(name, str);
        m_age = age;
        cout<<"A person whose name is ""\""<<name<<"\""<<" and age is "<<m_age<<" is created!"<<endl;
    }
    Person() : name("no name"),m_age(0)
    {
        cout<<"A person whose name is ""\""<<name<<"\""<<" and age is "<<m_age<<" is created!"<<endl;
    }
//    Person()
//    {
//        name = new char[80];
//        strcpy(name,"no name");
//        m_age = 0;
//        cout<<"A person whose name is ""\""<<name<<"\""<<" and age is "<<m_age<<" is created!"<<endl;
//    }
    Person(const Person &a)
    {
        name = new char[strlen(a.name) + 1];
        strcpy(name,a.name);
        m_age = a.m_age;
        cout<<"A person whose name is ""\""<<name<<"\""<<" and age is "<<m_age<<" is cloned!"<<endl;
    }
    void showPerson()
    {
        //cout<<"This person is ""\""<<name<<"\""<<" whose age is "<<m_age<<"."<<endl;
        cout<<"This person is ""\""<<name<<"\""<<" whose age is "<<m_age<<"."<<endl;
    }
    Person& setName(char str[])
    {
        delete []name;
        name = new char[strlen(str) + 1];
        strcpy(name,str);
        return *this;
    }
    Person& setAge(int age)
    {
        m_age = age;
        return *this;
    }
    ~Person()
    {

        cout<<"A person whose name is ""\""<<name<<"\""<<" and age is "<<m_age<<" is erased!"<<endl;

    }
private:
    char* name;
    int m_age;
};
int main()
{
    int cases;
    char str[80];
    int age;

    Person noname, Tom("Tom", 16), anotherTom(Tom);
    cin>>cases;
    for (int ca = 0; ca < cases; ca++)
    {
        cin>>str>>age;
        Person newPerson(str, age);
        newPerson.showPerson();
    }
    cout<<"change : ";
    anotherTom.setName(str).setAge(18);
    anotherTom.showPerson();
    noname.showPerson();
    return 0;
}
//#include<iostream>
//#include<cstring>
//#include<string>
//using namespace std;
//class Person{
//private:
//    string name;
//    int age;
//public:
//    Person()
//    {
//        name="no name";
//        age=0;
//        cout<<"A person whose name is "<<'"'<<name<<'"'<<" and age is "<<age<<" is created!"<<endl;
//    }
//    Person(string ch,int num)
//    {
//        name=ch;
//        age=num;
//        cout<<"A person whose name is "<<'"'<<name<<'"'<<" and age is "<<age<<" is created!"<<endl;
//
//    }
//    Person(const Person& another)
//    {
//        name=another.name;
//        age=another.age;
//        cout<<"A person whose name is "<<'"'<<name<<'"'<<" and age is "<<age<<" is cloned!"<<endl;
//    }
//    ~Person()
//    {
//
//        cout<<"A person whose name is "<<'"'<<name<<'"'<<" and age is "<<age<<" is erased!"<<endl;
//    }
//
//    void showPerson();
//    Person& setName(string);
//    Person& setAge(int);
//};
//void Person::showPerson()
//{
//    cout<<"This person is "<<'"'<<name<<'"'<<" whose age is "<<age<<"."<<endl;
//}
//Person& Person::setName(string c)
//{
//    name=c;
//    return *this;
//}
//Person& Person::setAge(int num)
//{
//    age=num;
//}
//int main()
//{
//    int cases;
//    char str[80];
//    int age;
//
//    Person noname, Tom("Tom", 16), anotherTom(Tom);
//    cin>>cases;
//    for (int ca = 0; ca < cases; ca++)
//    {
//        cin>>str>>age;
//        Person newPerson(str, age);
//        newPerson.showPerson();
//    }
//    anotherTom.setName(str).setAge(18);
//    anotherTom.showPerson();
//    noname.showPerson();
//    return 0;
//}

