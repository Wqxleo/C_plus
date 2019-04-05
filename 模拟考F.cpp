#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    int n,Max,num;;
    vector<int> v;
    while(cin>>n)
    {
        v.push_back(n);
    }
    vector<int> :: iterator itr;
    itr = v.begin();
    Max = *itr;
    num = 1;
    for(itr = v.begin() + 1;itr != v.end();itr++)
    {
        if(*itr == Max)
        {
            num++;
        }
        if(Max < *itr)
        {
            Max = *itr;
            num = 1;
        }

    }
    cout<<"There are "<<num<<" maximum number "<<Max<<"."<<endl;
}
