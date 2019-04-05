#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;
class Data
{
public:
    Data()
    {

    }
    void setValue(int n)
    {
        value = n;
    }
    bool isPalindrome()
    {
        if(value < 0)
        {
            value = -value;
        }
        string str;
        stringstream stream;
        stream<<value;
        stream>>str;
        int i,j;
        for(i = 0, j = str.size()-1;i < str.size();i++,j--)
        {
            if(str[i] != str[j])
                return false;
        }
        return true;
    }
private:
    int value;
};
int main()
{
    Data data;
    int v;
    while (cin>>v)
    {
        data.setValue(v);
        if (data.isPalindrome())
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
