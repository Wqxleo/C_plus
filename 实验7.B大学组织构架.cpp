//#include <iostream>
//#include <vector>
//#include <iterator>
//using namespace std;
//class Orgnization
//{
//public:
//    virtual void show()
//    {
//
//    }
//protected:
//    string m_name;
//    string m_leader;
//};
//class College : public Orgnization
//{
//public:
//    College(string name, string leader)
//    {
//        m_name = name;
//        m_leader = leader;
//    }
//    void show()
//    {
//        cout<<"Dean of "<<m_name<<" is "<<m_leader<<endl;
//    }
//private:
//
//};
//
//class Department : public Orgnization
//{
//public:
//    Department(string name, string leader)
//    {
//        m_name = name;
//        m_leader = leader;
//    }
//    void show()
//    {
//        cout<<"Director of "<<m_name<<" is "<<m_leader<<endl;
//    }
//private:
//
//};
//int main()
//{
//    vector<Orgnization*> university;
//    vector<Orgnization*>::iterator itr;
//    int n, i, t;
//    string str1, str2;
//    cin>>n;
//    for (i = 0; i < n; i++)
//    {
//        cin>>t;
//        cin.ignore();
//        getline(cin, str1);
//        getline(cin, str2);
//        if (t == 0)
//            university.push_back(new College(str1, str2));
//        else
//            university.push_back(new Department(str1, str2));
//    }
//    for (itr = university.begin(); itr != university.end(); itr++)
//        (*itr)->show();
//    return 0;
//}

#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;
int main()
{
    string a,c;
    int b;
    a = "1234";
    c = "abc";
    b = a[0] - '0';
    cout<<b;
    c[0] = b+'0';
//    c.insert(0,b+'0');
    cout<<c;
}
