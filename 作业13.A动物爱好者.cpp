#include <iostream>
using namespace std;
class Animal
{
public:
    Animal()
    {

    }
    ~Animal()
    {

    }
    void setAnimal(string name,int num)
    {
        m_name = name;
        m_num = num;
    }
    int getNum() const
    {
        return m_num;
    }
    string getName() const
    {
        return m_name;
    }
    Animal& operator=(const Animal &an)
    {
        m_name = an.m_name;
        m_num = an.m_num;
        return *this;
    }
private:
    string m_name;
    int m_num;
};
class AnimalList
{
public:
    AnimalList(Animal *animals,int n)
    {
        int i;
        //指针要先申请空间
        animalList = new Animal[n];
        for(i = 0;i < n;i++)
        {
            animalList[i] = animals[i];
        }
        numOfAnimal = n;
    }
    ~AnimalList()
    {

    }
    int operator[](string name)
    {
        Animal *p;
        for(p = animalList; p < animalList+numOfAnimal;p++)
        {
            if(p->getName() == name)
            {
                return p->getNum();
            }
        }
        return -1;

    }
private:
    Animal *animalList;
    int numOfAnimal;
};
int main()
{
    int cases;
    string name;
    int num;
    cin>>cases;
    Animal animals[cases];
    for (int i = 0; i < cases; i++)
    {
        cin>>name>>num;
        animals[i].setAnimal(name, num);
    }
    AnimalList animalList(animals, cases);

    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        cin>>name;
        if (animalList[name] != -1)
            cout<<"There are "<<animalList[name]<<" "<<name<<"s."<<endl;
        else
            cout<<"There is none "<<name<<"."<<endl;
    }
    return 0;
}
