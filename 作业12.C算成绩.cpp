#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <iomanip>
using namespace std;
int main()
{
    int m,n,i,j,k;
    vector<string> students;
    vector<string> :: iterator itr1;
    string name;
    //输入人名的个数
    cin>>m;
    vector<double> scour[m];
    vector<double> :: iterator itr3;
    //输入人名
    for(i = 0; i < m; i++)
    {
        cin>>name;
        students.push_back(name);
    }
    //布置作业的次数
    cin>>n;
    double submit,ac,Max;
    map<string,double> record;
    map<string,double> :: iterator itr2;

    //循环输入作业提交情况
    for(i = 0; i < n; i++)
    {
        Max = 0;
        cin>>submit;
        for(j = 0; j < submit; j++)
        {
            cin>>name>>ac;
            if(Max < ac)
                Max = ac;
            record.insert(make_pair(name,ac));
        }
        //cout<<Max<<endl;
        j = 0;
        int flag;
        for(itr1 = students.begin(); itr1 != students.end(); itr1++)
        {
            flag = 0;
            for(itr2 = record.begin(); itr2 != record.end(); itr2++)
            {
                if(itr2->first == *itr1)
                {
                    //cout<<itr2->second/Max*100<<" ";
                    scour[j].push_back(itr2->second/Max*100);
                    flag = 1;
                }
            }
            if(flag == 0)
                scour[j].push_back(0);
            j++;
        }
        record.clear();
    }
    double tmp;
    for(i = 0; i < m; i++)
    {
        tmp = 0;
        for(itr3 = scour[i].begin(); itr3 != scour[i].end(); itr3++)
        {
            tmp += *itr3;
        }
        scour[i].push_back(tmp/n);
    }
    cout<<left<<setw(12)<<"NAME";
    for(i = 0; i < n; i++)
    {
        cout<<left<<"TEST"<<setw(3)<<i+1;
    }
    cout<<"FINAL"<<endl;
    itr1 = students.begin();
    for(i = 0; i < m; i++)
    {
        cout<<left<<setw(12)<<*itr1;
        for(itr3 = scour[i].begin(); itr3 != scour[i].end(); itr3++)
        {
            if(itr3 != scour[i].end()-1)
                cout<<left<<setw(7)<<setprecision(2) <<std::fixed <<*itr3;
            else
                cout<<left<<setw(6)<<setprecision(2) <<std::fixed <<*itr3;
        }
        //cout<<"a";
        cout<<endl;
        itr1++;
    }
    return 0;
}
