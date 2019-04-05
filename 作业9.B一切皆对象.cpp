#include <iostream>
using namespace std;
class Thing
{
public:
    Thing()
    {
        m_name = "null";
       cout<<"A thing without name is created!"<<endl;
    }
    Thing(string name)
    {
        m_name = name;
        cout<<"A thing named by "<<m_name<<" is created!"<<endl;
    }
    Thing(const Thing &t)
    {
         if(t.m_name != "null")
         {
             m_name = t.m_name;
             cout<<"A thing named by "<<m_name<<" is copied!"<<endl;
         }
         else
         {
             m_name = t.m_name;
             cout<<"A thing without name is copied!"<<endl;
         }
    }
    ~Thing()
    {
        if(m_name != "null")
         {
             //cout<<m_name<<endl;
             cout<<"A thing named by "<<m_name<<" is erased!"<<endl;
         }
         else
         {
             //cout<<m_name<<endl;
             cout<<"A thing without name is erased!"<<endl;
         }
    }
private:
    string m_name;
};
int main()
{
    string name;
    Thing Thing1, Thing2(Thing1);
    cin>>name;
    Thing Thing3(name);
    Thing Thing4(Thing3);
    return 0;
}
