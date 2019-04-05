#include <iostream>
#include <set>
#include <iterator>
#include<algorithm>
using namespace std;
int main()
{
    set<unsigned int> eg1,eg2,eg3;
    unsigned int tmp;
    while(cin>>tmp)
    {
        while(tmp != 0)
        {
            eg1.insert(tmp);
            cin>>tmp;
        }
        cin>>tmp;
        while(tmp != 0)
        {
            eg2.insert(tmp);
            cin>>tmp;
        }
        set_difference(eg1.begin(),eg1.end(),eg2.begin(),eg2.end(),insert_iterator<set<unsigned int> >(eg3,eg3.begin()));
        if(eg3.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

        eg1.clear();
        eg2.clear();
        eg3.clear();
    }
    return 0;
}
