#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    int sum;
    int tmp;
    vector<int> arr;
    vector<int>::iterator itr1,itr2;
    cin>>sum;
    while (cin>>tmp)
    {
        arr.push_back(tmp);
    }
    for(itr1 = arr.begin(),itr2 = arr.end(); itr1<itr2; itr1++)
    {
        for(itr2 = arr.end(); itr2 > itr1; itr2--)
        {
            if(*itr1 + *itr2 == sum)
            {
                cout<<*itr1<<" + "<<*itr2<<" = "<<sum<<endl;
                break;
            }
        }
    }
    return 0;
}
