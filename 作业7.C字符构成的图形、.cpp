#include <iostream>
using namespace std;
class CharGraph
{
public:
    CharGraph(int n, char c)
    {
        m_n = n;
        m_c = c;
    }
    ~CharGraph()
    {

    }
    void print()
    {
        int i,j;

        if(m_n > 0)
        {
            for(i = 0; i < m_n; i++)
            {
                for(j = 0; j <=i; j++)
                {
                    cout<<m_c;
                }
                cout<<endl;
            }
        }
        if(m_n == 0)
        {
            cout<<endl;
        }
        if(m_n < 0)
        {
            for(i = 0; i < -m_n; i++)
            {
                for(j = 0; j < -m_n-i; j++)
                {
                    cout<<m_c;
                }
                cout<<endl;
            }
        }
    }
private:
    int m_n;
    char m_c;

};
int main()
{
    int cases, n;
    char c;
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        cin>>n>>c;
        CharGraph cGraph(n, c);
        cGraph.print();
    }
    return 0;
}
