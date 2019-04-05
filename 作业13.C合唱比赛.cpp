#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <iomanip>
using namespace std;
class Team
{
public:
    Team()
    {

    }
    Team(string name)
    {
        m_name = name;
    }
    ~Team()
    {

    }
    void Addscores(double s)
    {
        scores.push_back(s);
    }
    void show()
    {
        cout<<setw(11)<<left<<m_name<<setprecision(2)<<fixed<<finalscores;
    }
    void compute()
    {
        vector<double> :: iterator itr;
        double Max,Min,sum;
        Max = sum = 0;
        Min = 100;
        for(itr = scores.begin(); itr != scores.end(); itr++)
        {
            sum += *itr;
            if(Max < *itr)
            {
                Max = *itr;
            }
            if(Min > *itr)
            {
                Min = *itr;
            }
        }
        finalscores = (sum-Max-Min)/(scores.size()-2);
    }
    double getFinal()
    {
        return finalscores;
    }
private:
    string m_name;
    vector<double> scores;
    double finalscores;
};
class Contest
{
public:
    void Input()
    {
        int M,N,P,i,j,k;
        m_N = N;
        string name;
        double tmp1,tmp2;
        cin>>M>>N>>P;
        for(i = 0; i < M; i++)
        {
            cin>>name;
            team.push_back(Team(name));
            for(j = 0; j < N; j++)
            {
                tmp2 = 0;
                for(k = 0;k < P;k++)
                {
                    cin>>tmp1;
                    tmp2 += tmp1;
                }
                team[i].Addscores(tmp2/P);
            }
        }

    }
    void Compute()
    {
        int j;
        for (j = 0; j < team.size(); j++)
        {
            team[j].compute();
        }
    }
    void Show()
    {
        vector<Team> :: iterator itr;
        for(itr = team.begin(); itr != team.end(); itr++)
        {
            itr->show();
            cout<<endl;
        }
    }
    void Sort()
    {
        //vector<Team> tmp;
        int i,j;
        //tmp = team;
        //team.clear();
        Team tmp;
        for(i = 1; i < team.size();i++)
            for(j = 0; j < team.size()-i;j++)
        {
            if(team[j].getFinal() < team[j+1].getFinal())
            {
                tmp = team[j+1];
                team[j+1] = team[j];
                team[j] = tmp;
            }
        }
    }
private:
   vector<Team> team;
   int m_N;
};
int main()
{
    Contest contest;
    contest.Input();
    contest.Compute();
    contest.Sort();
    contest.Show();
    return 0;
}
