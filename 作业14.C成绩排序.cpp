#include <iostream>
using namespace std;
class Student
{
public:
    Student()
    {

    }
    ~Student()
    {

    }
    void setStudent(string name, int s)
    {
        m_name = name;
        score = s;
    }
    bool operator>(Student &s)
    {
        if(score > s.score)
        {
            return true;
        }
        else if(score < s.score)
        {
            return false;
        }
        else
        {
            if(m_name < s.m_name)
            {
                return true;
            }
            else
                return false;
        }
    }
    friend ostream& operator<<(ostream &os,const Student &s);
private:
    string m_name;
    int score;
};
ostream& operator<<(ostream &os,const Student &s)
{
    os<<s.score<<" "<<s.m_name;
    return os;
}
int main()
{
    int cases;
    string name;
    int score;
    cin>>cases;
    Student students[cases], temp;
    for (int i = 0; i < cases; i++)
    {
        cin>>name>>score;
        students[i].setStudent(name, score);
    }
    for (int i = 0; i < cases; i++)
    {
        for (int j = 0; j < cases - i - 1; j++)
        {
            if (!(students[j] > students[j + 1]))
            {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < cases; i++)
        cout<<students[i]<<endl;
    return 0;
}
