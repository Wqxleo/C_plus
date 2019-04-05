#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <iomanip>
#include <cstring>
using namespace std;
class Guest
{
public:
    Guest(string name)
    {
        m_name = name;
    }
    void addeat()
    {
        int num;
        cin>>num;
        string name;
        int n;
        for(int i = 0; i < num; i++)
        {
            cin>>name>>n;
            eat.insert(make_pair(name,n));
        }
    }
    string getname()
    {
        return m_name;
    }
    void show()
    {
        cout<<m_name<<endl;
        map<string,int> :: iterator itr;
        for(itr = eat.begin(); itr != eat.end(); itr++)
        {
            cout<<itr->first<<" "<<itr->second<<" "<<endl;
        }

    }
//    double getspence(map<string, double> c)
//    {
//
//    }
    map<string,int> geteat()
    {
        return eat;
    }
private:
    string m_name;
    map<string,int> eat;
    double spence;
};
class CarteList
{
public:
    void Input()
    {
        int num;
        cin>>num;
        string name;
        double price;
        int i;
        for(i = 0; i < num; i++)
        {
            cin>>name>>price;
            carte.insert(make_pair(name,price));
        }
        cin>>num;
        for(i = 0; i < num; i++)
        {
            int n;
            cin>>name;
            guests.push_back(Guest(name));
            guests[i].addeat();
        }
    }
    void compute()
    {
        int i;
        map<string, double> :: iterator itr1;
        map<string,int> :: iterator itr2;
        for(i = 0; i < guests.size(); i++)
        {

            double sum = 0;
            for(itr2 = guests[i].geteat().begin(); itr2 != guests[i].geteat().end(); itr2++)
            {
                for(itr1 = carte.begin(); itr1 != carte.end(); itr1++)
                {
                    cout<<itr2->first<<" "<<itr1->first<<endl;
                    if(itr2->first == itr1->first)
                    {
                        cout<<itr2->second<<" "<<itr1->second<<endl;
                        sum += (itr2->second)*(itr1->second);
                        break;
                    }
                }
            }
            cout<<guests[i].getname()<<" ";
            cout<<sum<<endl;
            List.insert(make_pair(guests[i].getname(),sum));
        }
    }
    void show()
    {
        vector<Guest> :: iterator itr;
        map<string, double> :: iterator itr1;
        for(itr1 = carte.begin(); itr1 != carte.end(); itr1++)
        {
            cout<<itr1->first<<" "<<itr1->second<<endl;
        }
        cout<<"guest"<<endl;
        for(itr = guests.begin(); itr != guests.end(); itr++)
        {
            itr->show();
        }

    }
//    void show()
//    {
//        map<string,double> :: iterator itr;
//        int len = 0;
//        for(itr = List.begin(); itr != List.end(); itr++)
//        {
//            if(len < itr->first.size())
//                len = itr->first.size();
//        }
//        cout<<setw(len+1)<<"Guest"<<"Price";
//        for(itr = List.begin(); itr != List.end(); itr++)
//        {
//            cout<<setw(len+1)<<itr->first<<itr->second<<endl;
//        }
//    }

private:
    map<string, double> carte;
    vector<Guest> guests;
    map<string,double> List;
};

int main()
{
    CarteList cartelist;
    cartelist.Input();
    cartelist.compute();
    //cartelist.show();
}
