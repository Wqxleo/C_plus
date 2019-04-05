#include <iostream>
#include <vector>
#include <iomanip>
#include <iterator>
using namespace std;
template <typename T>
class DataVector
{
public:
    void show()
    {
        typename vector<T>::iterator itr;//vector<T>T如果是不确定的，则前面要加typename
        for (itr = members.begin(); itr != members.end(); itr++)
        {
            if(itr == members.begin())
            {
                cout<<*itr;
            }
            else
            {
                cout<<" "<<*itr;
            }

        }
        cout<<endl;
    }
    T getSum();
    void clearVector()
    {
        members.clear();
    }
    vector<T>& getVector()
    {
        return members;
    }
private:
    vector<T> members;
};
template <typename T>
T DataVector<T>::getSum()
{
    T tmp = 0;
    typename vector<T>::iterator itr;//vector<T>T如果是不确定的，则前面要加typename
    for (itr = members.begin(); itr != members.end(); itr++)
    {
        tmp += *itr;
    }
    return tmp;
}


int main()
{
    int cases, num, iData;
    double dData;
    DataVector<int> iVector;
    DataVector<double> dVector;
    char type;
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        cin>>type;
        switch(type)
        {
        case 'i':
            iVector.clearVector();
            cin>>num;
            for (int j = 0; j < num; j++)
            {
                cin>>iData;
                iVector.getVector().push_back(iData);
            }
            iVector.show();
            cout<<iVector.getSum()<<endl;
            break;
        case 'd':
            dVector.clearVector();
            cin>>num;
            for (int j = 0; j < num; j++)
            {
                cin>>dData;
                dVector.getVector().push_back(dData);
            }
            dVector.show();
            cout<<setprecision(2)<<fixed<<dVector.getSum()<<endl;
        }
    }
    return 0;
}
