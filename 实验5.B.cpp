#include <iostream>
#include <map>
using namespace std;
int main()
{
    int num;
    map<int, string> students;
    map<int,string>::iterator itr;
    cin>>num;
    int i;
    for (i = 0; i < num; i++)
    {
        int id;
        string name;
        cin>>id>>name;
        students.insert(make_pair(id, name));
    }
    while(cin>>num)
    {
        itr = students.find(num);
        if(itr == students.end())
        {
            if(itr->first == num)
            cout<<itr->second<<endl;
            else
               cout<<"NULL"<<endl;
        }
        else
            cout<<itr->second<<endl;
    }
    return 0;

}
