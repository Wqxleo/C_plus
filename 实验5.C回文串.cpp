#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    char c;
    vector<char> str;
    vector<char> :: iterator itr1,itr2;
    while(cin>>c)
    {
        str.push_back(c);
    }
    itr2 = str.end()-1;//vector容器的end是指向最后一个元素的下一个位置，使用时要将迭代器减1,才能获取到最后一个
    for(itr1 = str.begin(); itr1 != str.end(); itr1++)
    {
        if(*itr1 != *itr2)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        itr2--;
    }
    cout<<"YES"<<endl;
    return 0;
}
