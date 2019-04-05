#include <iostream>
using namespace std;
class Thing
{
public:
    Thing(string str)
    {
        name = str;
        cout<<"Construct a thing "<<str<<endl;
    }
    ~Thing()
    {
        cout<<"Destroy a thing "<<name<<endl;
    }
private:
    string name;
};
int main()
{
    Thing A("Car");
    string str;
    cin>>str;
    Thing B(str);
    return 0;
}

