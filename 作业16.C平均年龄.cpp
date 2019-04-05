#include <iostream>
#include <map>
#include <iterator>
#include <iomanip>
using namespace std;
class Persons
{
public:
    void addAPerson(string name, int age)
    {
        person.insert(make_pair(name,age));
    }
    double getAveAge()
    {
        map<string,int> :: iterator itr;
        double tmp = 0;
        for(itr = person.begin(); itr != person.end(); itr++)
        {
            tmp += itr->second;
        }
        return tmp/person.size();
    }
private:
    map<string,int> person;
};
int main()
{
    int cases, age;
    string name;
    Persons persons;
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        cin>>name>>age;
        persons.addAPerson(name, age);
    }
    cout<<setprecision(2)<<fixed<<persons.getAveAge()<<endl;
}
