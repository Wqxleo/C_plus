#include <iostream>
using namespace std;
class Students
{
public:
    Student(string name)
    {
        m_name = name;
    }
    ~Student()
    {

    }
    void getscour()
    {

    }
    void getarg()
    {

    }
    void show()
    {

    }
private:
    string m_name;
    vector<double> scour;
};
int main()
{
    double m,n,submint,i,j,ac;
    cin>>m;
    string name;
    for(i = 0; i < m; i++)
    {
        cin>>name;
        Students student[i](name);
    }
    cin>>n;
    map<string,int> record;
    double Max;
    for(i = 0; i < n; i++)
    {
        Max = 0;
        cin>>submint;
        for(j = 0; j < submit; j++)
        {
            cin>>name>>ac;
            if(Max < ac)
            {
                Max = ac;
            }
            reocrd.insert(make_pair(name,ac));
        }
    }
}
