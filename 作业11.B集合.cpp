#include <iostream>
#include <set>
#include<algorithm>
#include <iterator>
using namespace std;
int main()
{
    set<int> eg1,eg2,eg3,eg4;
    int n,m,p,i;
    cin>>n;
    for(i = 0; i < n; i++)
    {
        cin>>m;
        int j,tmp;;
        for(j = 0; j < m; j++)
        {
            cin>>tmp;
            eg1.insert(tmp);
        }
        cin>>p;
        for(j = 0; j < p; j++)
        {
            cin>>tmp;
            eg2.insert(tmp);
        }
        cout<<"Case# "<<i+1<<":"<<endl<<"A = {";
        set<int> :: iterator itr;
        for(itr = eg1.begin(); itr != eg1.end(); itr++){
            if(itr != eg1.begin())
                cout << ", ";
            cout << *itr;
        }
        cout<<"}"<<endl;

        cout<<"B = {";
        for(itr = eg2.begin(); itr != eg2.end(); itr++){
            if(itr != eg2.begin())
                cout << ", ";
            cout << *itr;
        }
        cout<<"}"<<endl;
//获得两个set的并
        cout<<"A u B = {";
        set_union(eg1.begin(),eg1.end(),eg2.begin(),eg2.end(),insert_iterator<set<int> >(eg4,eg4.begin()));//注意第五个参数的形式
        for(itr = eg4.begin(); itr != eg4.end(); itr++)
        {
            if(itr != eg4.begin())
                cout << ", ";
            cout << *itr;
        }
        cout << "}" << endl;
//获得两个set的交，注意进行集合操作之前接收结果的set要调用clear()函数清空一下
        eg3.clear();
        set_intersection(eg1.begin(),eg1.end(),eg2.begin(),eg2.end(),insert_iterator<set<int> >(eg3,eg3.begin()));
        cout<<"A n B = {";
        for(itr = eg3.begin(); itr != eg3.end(); itr++)
        {
            if(itr != eg3.begin())
                cout << ", ";
            cout << *itr;
        }
        cout << "}" << endl;
//获得两个set的差
        eg3.clear();
        set_difference(eg1.begin(),eg1.end(),eg2.begin(),eg2.end(),insert_iterator<set<int> >(eg3,eg3.begin()));
        cout<<"A - B = {";
        for(itr = eg3.begin(); itr != eg3.end(); itr++)
        {
            if(itr != eg3.begin())
                cout << ", ";
            cout << *itr;
        }
        cout << "}" << endl;

        eg3.clear();
        set_difference(eg4.begin(),eg4.end(),eg1.begin(),eg1.end(),insert_iterator<set<int> >(eg3,eg3.begin()));
        cout<<"SA = {";
        for(itr = eg3.begin(); itr != eg3.end(); itr++)
        {
            if(itr != eg3.begin())
                cout << ", ";
            cout << *itr;
        }
        cout << "}" << endl;
        eg3.clear();
        set_difference(eg4.begin(),eg4.end(),eg2.begin(),eg2.end(),insert_iterator<set<int> >(eg3,eg3.begin()));
        cout<<"SB = {";
        for(itr = eg3.begin(); itr != eg3.end(); itr++)
        {
            if(itr != eg3.begin())
                cout << ", ";
            cout << *itr;
        }
        cout << "}" << endl;
        eg1.clear();
        eg2.clear();
        eg3.clear();
        eg4.clear();
    }
    return 0;
}
