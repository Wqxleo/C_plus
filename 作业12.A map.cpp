#include <iostream>
#include <map>
using namespace std;
int main()
{

    map<string,int> fruits;
    map<string,int> :: iterator itr;
    string name;
    int num, n, i;
    while(cin>>n)
    {
        for(i = 0; i < n; i++)
        {
            cin>>name>>num;
            for(itr = fruits.begin(); itr != fruits.end(); itr++)
            {
                if(name == itr->first)
                {
                    itr->second += num;
                    break;
                }
            }
            fruits.insert(make_pair(name,num));
        }
        for(itr = fruits.begin(); itr != fruits.end(); itr++)
        {
            cout<<itr->first<<":"<<itr->second<<endl;
        }
        fruits.clear();
    }
    return 0;
}
