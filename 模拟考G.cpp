#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
class Animal
{
public:
    virtual void eat() = 0;
private:

};
class Dog : public Animal
{
public:
    void eat()
    {
        cout<< "Dog eats bone."<<endl;
    }
private:

};
class Cat : public Animal
{
public:
    void eat()
    {
        cout<< "Cat eats fish."<<endl;
    }
private:

};
class Sheep : public Animal
{
public:
    void eat()
    {
        cout<< "Sheep eats grass."<<endl;
    }
private:

};
class Chicken : public Animal
{
public:
    void eat()
    {
        cout<< "Chicken eats worm."<<endl;
    }
private:

};
int main()
{
    int c;
    vector<Animal*> animals;
    vector<Animal*>::iterator itr;
    while(cin>>c)
    {
        switch(c)
        {
        case 0 :
            animals.push_back(new Dog());
            break;
        case 1:
            animals.push_back(new Cat());
            break;
        case 2:
            animals.push_back(new Sheep());
            break;
        case 3:
            animals.push_back(new Chicken());
        }
    }
    for (itr = animals.begin(); itr != animals.end(); itr++)
        (*itr)->eat();
    return 0;
}
