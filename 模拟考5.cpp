#include <iostream>
using namespace std;
template <typename T>
class Sample
{
public:
    Sample(T a)
    {
        value = a;
        cout<<"Sample "<<value<<" is created."<<endl;
    }
    Sample(const Sample &t)
    {
        value = t.value;
        cout<<"Sample "<<value<<" is copied."<<endl;
    }
    void show()
    {
        cout<<value<<endl;
    }
    void add(Sample s)
    {
        value += s.value;

    }
private:
    T value;
};
//template <typename T>
//int T Sample<T> :: num = 1;
int main()
{
    int a, b;
    double c, d;
    cin>>a>>b>>c>>d;
    Sample<int> s1(a), s2(b), s3(s1);
    Sample<double> s4(c), s5(d), s6(s5);
    s1.add(s2);
    s1.show();
    s5.add(s4);
    s5.show();
    return 0;
}
