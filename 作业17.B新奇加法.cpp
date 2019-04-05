#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
class newInt
{
public:
    newInt operator+(const newInt &n)
    {
        newInt tmp;
        tmp.value = 0;
        int arr1[100],arr2[100],arr3[100];
        int tmp1 = value;
        int tmp2 = n.value;
        int i, j;
        i = j = 0;
        do
        {
            arr1[i] = tmp1%10;
            tmp1 /= 10;
            i++;
        }while(tmp1);

        do
        {
            arr2[j] = tmp2%10;
            tmp2 /= 10;
            j++;
        }while(tmp2);
        int k,flag = 1;
        for(k = 0; k < i&&k < j;k++)
        {
//            cout<<arr1[k]<<" "<<arr2[k]<<" ";
            tmp.value += ((arr1[k]+arr2[k])%10)*flag;
            flag *= 10;
        }
        if(k == i)
        {
            for(k = i; k < j; k++)
            {
                tmp.value += arr2[k]*flag;
                flag *= 10;
            }
        }
        else
        {
            for(k = j; k < i; k++)
            {
                tmp.value += arr1[k]*flag;
                flag *= 10;
            }
        }
        return tmp;
    }
    friend istream& operator>>(istream& is, newInt &n);
    friend ostream& operator<<(ostream& os, const newInt &n);
private:
    int value;
};
istream& operator>>(istream& is, newInt &n)
{
    is>>n.value;
    return is;
}
ostream& operator<<(ostream& os, const newInt &n)
{

    os<<n.value;
    return os;
}
int main()
{
    int cases;
    newInt a, b, c;
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        cin>>a>>b;
        c = a + b;
        cout<<a<<" + "<<b<<" = "<<c<<endl;
    }
    return 0;
}
