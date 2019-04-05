#include <iostream>
#include <iomanip>
#include <typeinfo>
using namespace std;
class Automobile
{
public:
    Automobile(double s)
    {
        speed = s;
    }
    virtual ~Automobile()
    {
        cout<<"An automobile is erased!"<<endl;
    }
    virtual void run() const = 0;
protected:
    double speed;
};
class Benz : public  Automobile
{
public:
    Benz(double s) : Automobile(s)
    {

    }
    ~Benz()
    {
        cout<<"A Benz is erased!"<<endl;
    }
    void run() const
    {
        cout<<"Benz at speed of "<<setprecision(2)<<std::fixed<<speed<<"km/h."<<endl;
    }
private:
};
class Buick : public  Automobile
{
public:
    Buick(double s) : Automobile(s)
    {

    }
    ~Buick()
    {
        cout<<"A Buick is erased!"<<endl;
    }
    void run() const
    {
        cout<<"Buick at speed of "<<setprecision(2)<<std::fixed<<speed<<"km/h."<<endl;
    }
private:
};
class Zhongba : public  Automobile
{
public:
    Zhongba(double s) : Automobile(s)
    {

    }
    ~Zhongba()
    {
        cout<<"A Zhongba is erased!"<<endl;
    }
    void run() const
    {
        cout<<"Zhongba at speed of "<<setprecision(2)<<std::fixed<<speed<<"km/h."<<endl;
    }
private:
};

class Beiqi : public  Automobile
{
public:
    Beiqi(double s) : Automobile(s)
    {

    }
    ~Beiqi()
    {
        cout<<"A Beiqi is erased!"<<endl;
    }
    void run() const
    {
        cout<<"Beiqi at speed of "<<setprecision(2)<<std::fixed<<speed<<"km/h."<<endl;
    }
private:
};

class Dayu : public  Automobile
{
public:
    Dayu(double s) : Automobile(s)
    {

    }
    ~Dayu()
    {
        cout<<"A Dayu is erased!"<<endl;
    }
    void run() const
    {
        cout<<"Dayu at speed of "<<setprecision(2)<<std::fixed<<speed<<"km/h."<<endl;
    }
private:
};

class Jianghuai : public  Automobile
{
public:
    Jianghuai(double s) : Automobile(s)
    {

    }
    ~Jianghuai()
    {
        cout<<"A Jianghuai is erased!"<<endl;
    }
    void run() const
    {
        cout<<"Jianghuai at speed of "<<setprecision(2)<<std::fixed<<speed<<"km/h."<<endl;
    }
private:
};

class  Driver
{
public:
    Driver(string n, char t)
    {
        name = n;
        type = t;
    }
    ~Driver()
    {

    }
    void Drive(Automobile*);
private:
    string name;
    char type;
};
void Driver::Drive(Automobile *automobile)
{
    switch (type)
    {
    case 'A':
        cout<<"Driver "<<name<<" can drive ";
        automobile->run();
        break;
    case 'B':
        if (typeid(*automobile) == typeid(Dayu) || typeid(*automobile) == typeid(Jianghuai))
            cout<<"Driver "<<name<<" cannot drive large bus."<<endl;
        else
        {
            cout<<"Driver "<<name<<" can drive ";
            automobile->run();
        }
        break;
    case 'C':
        if (typeid(*automobile) != typeid(Benz) && typeid(*automobile) != typeid(Buick))
            cout<<"Driver "<<name<<" cannot drive bus."<<endl;
        else
        {
            cout<<"Driver "<<name<<" can drive ";
            automobile->run();
        }
        break;
    }
}


int main()
{
    string name;
    char type;
    double speed;
    char automobileType;
    int cases;
    Automobile *automobile;
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        cin>>name>>type>>automobileType>>speed;
        Driver driver(name, type);
        switch (automobileType)
        {
        case 'a':
            automobile = new Benz(speed);
            break;
        case 'b':
            automobile = new Buick(speed);
            break;
        case 'c':
            automobile = new Zhongba(speed);
            break;
        case 'd':
            automobile = new Beiqi(speed);
            break;
        case 'e':
            automobile = new Dayu(speed);
            break;
        case 'f':
            automobile = new Jianghuai(speed);
            break;
        }
        driver.Drive(automobile);
        delete automobile;
    }
    return 0;
}
