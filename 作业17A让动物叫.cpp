#include <iostream>
using namespace std;
class Animal
{
public:
    Animal(string n)
    {
        name = n;
    }
    virtual void sound() = 0;
protected:
    string name;
};
class Cock : public Animal
{
public:
    Cock(string n) : Animal(n)
    {

    }
    void sound()
    {
        cout<<name<<" is a cock, and it can crow."<<endl;
    }
private:

};
class Turkey : public Animal
{
public:
    Turkey(string n) : Animal(n)
    {

    }
    void sound()
    {
        cout<<name<<" is a turkey, and it can gobble."<<endl;
    }
private:

};
class Duck : public Animal
{
public:
    Duck(string n) : Animal(n)
    {

    }
    void sound()
    {
        cout<<name<<" is a duck, and it can quack."<<endl;
    }
private:

};
int main()
{
    int cases;
    string name;
    char type;
    Animal *animal;
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
       cin>>name>>type;
       switch(type)
       {
        case 'A':
            animal = new Duck(name);
            break;
        case 'B':
            animal = new Turkey(name);
            break;
        case 'C':
            animal = new Cock(name);
            break;
       }
       animal->sound();
    }
    return 0;
}
