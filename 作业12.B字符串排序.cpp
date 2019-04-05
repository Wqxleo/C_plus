#include <iostream>
#include <string>
#include <set>
#include <iterator>
using namespace std;
int main()
{
    string tmp;
    multiset<string> eg;
    multiset<string> :: iterator itr;
    int n,i;
    cin>>n;
    for(i = 0; i < n; i++)
    {
        cin>>tmp;
        eg.insert(tmp);
    }
    for(itr = eg.begin(); itr != eg.end(); itr++)
    {
        cout<<*itr<<endl;
    }
    return 0;
}
