#include <iostream>
using namespace std;
class Vechicle
{
public:
    Vechicle(int s)
    {
        speed = s;
        numOfVechicles++;
    }
    virtual ~Vechicle()
    {
        cout<<"A vechicle is deleted."<<endl;
    }
    static int getNumOfVechicles()
    {
        return numOfVechicles;
    }
    virtual void show() = 0;
protected:
    int speed;
private:
   static int numOfVechicles;
};
int Vechicle :: numOfVechicles = 0;

class Bike : public Vechicle
{
public:
    Bike(int s) : Vechicle(s)
    {

    }
    ~Bike()
    {
        cout<<"A bike is deleted."<<endl;
    }
    void show()
    {
        cout<<"A bike's speed is "<<speed<<"km/h."<<endl;
    }
private:

};
class MotoBike : public Vechicle
{
public:
    MotoBike(int s) : Vechicle(s)
    {

    }
    ~MotoBike()
    {
        cout<<"A motobike is deleted."<<endl;
    }
    void show()
    {
        cout<<"A motobike's speed is "<<speed<<"km/h."<<endl;
    }
private:

};
class Car : public Vechicle
{
public:
    Car(int s) : Vechicle(s)
    {

    }
    ~Car()
    {
        cout<<"A car is deleted."<<endl;
    }
    void show()
    {
        cout<<"A car's speed is "<<speed<<"km/h."<<endl;
    }
private:

};
class Person
{
public:
    Person(string n)
    {
        name = n;
    }
    ~Person()
    {

    }
    void drive(Vechicle &v)
    {
        cout<<name<<" drives. ";
        v.show();

    }
private:
    string name;

};
int main()
{
    int cases, n;
    char c;
    string name;
    Vechicle* vechicle;
    cout<<"In beginning, we have "<<Vechicle::getNumOfVechicles()<<" vechicles."<<endl;
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        cin>>name>>c>>n;
        Person person(name);
        switch (c)
        {
        case 'B':
            vechicle = new Bike(n);
            break;
        case 'M':
            vechicle = new MotoBike(n);
            break;
        case 'C':
            vechicle = new Car(n);
            break;
        }
        person.drive(*vechicle);
        delete vechicle;
    }
    cout<<"At the end, we have "<<Vechicle::getNumOfVechicles()<<" vechicles."<<endl;
    return 0;
}
