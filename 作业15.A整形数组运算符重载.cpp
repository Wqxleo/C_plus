#include <iostream>
using namespace std;
class Array
{
public:
    Array():length(0),means(NULL)
    {

    }
    ~Array()
    {

    }
    bool operator==(const Array &a)
    {

//        if(*this == a)
//        {
//            return true;
//        }
//        else
//        {
        int i;
        if(length != a.length)
            return false;
        else
        {
            for(i = 0; i < length; i++)
            {
                if(means[i] != a.means[i])
                    return false;
            }
            return true;
        }

//        }
    }
    friend istream& operator>>(istream& is,Array &a);
    friend ostream& operator<<(ostream& os,const Array &a);


private:
    int length;
    int *means;
};
istream& operator>>(istream& is,Array &a)
{
    is>>a.length;
    a.means = new int[a.length];
    for(int i = 0; i < a.length; i++)
    {
        is>>a.means[i];
    }
    return is;
}
ostream& operator<<(ostream& os,const Array &a)
{
    for(int i = 0; i < a.length; i++)
    {
        if(i == 0)
            os<<a.means[i];
        else
            os<<" "<<a.means[i];

    }
    //delete []a.means;
    return os;
}
int main()
{
    int cases;
    cin>>cases;
    Array arraies[cases];
    for (int i = 0; i < cases; i++)
    {
        cin>>arraies[i];
    }
    cout<<arraies[0]<<endl;
    for (int i = 1; i < cases; i++)
    {
        if (arraies[i] == arraies[i - 1])
        {
            cout<<arraies[i]<<" "<<"equal to above."<<endl;
        }
        else
        {
            cout<<arraies[i]<<" "<<"unequal to above."<<endl;
        }
    }
    return 0;
}
