#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class Equation
{
public:
    Equation(double a, double b, double c)
    {
        m_a = a;
        m_b = b;
        m_c = c;
    }
    void solve()
    {
        double s;
        s = sqrt(m_b*m_b - 4*m_a*m_c);
        m_x1 = (-m_b+s)/(2*m_a);
        m_x2 = (-m_b-s)/(2*m_a);
    }
    void printRoot()
    {
//        double tep;
//        if(m_x1 < m_x2)
//        {
//            tep = m_x1;
//            m_x1 = m_x2;
//            m_x2 = tep;
//        }
        cout<<setprecision(2)<<fixed<<m_x1<<" "<<setprecision(2)<<fixed<<m_x2<<endl;
    }
private:
    double m_a;
    double m_b;
    double m_c;
    double m_x1;
    double m_x2;

};
int main()
{
    double a, b, c;
    while (cin>>a>>b>>c)
    {
        Equation equ(a,b,c);
        equ.solve();
        equ.printRoot();
    }
    return 0;
}
