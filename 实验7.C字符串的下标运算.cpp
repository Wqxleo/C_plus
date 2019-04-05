#include <iostream>
#include <cstring>
using namespace std;
class MyString
{
public:
    int operator[](char ch)
    {
        int i,len;
        len = strlen(str);
        for(i = num;i < len+1; i++)
        {
            if(i == len)
                return -1;
            if(str[i] == ch)
            {
                num = i+1;
                return i;
            }
        }

    }
    friend istream& operator>>(istream &is,MyString &str);
private:
    char str[101];
    static int num;
};
istream& operator>>(istream &is,MyString &s)
{
      is>>s.str;
}
int MyString :: num = 0;
int main()
{
    MyString mystr;
    char c;
    int pos;
    cin>>mystr>>c;
    do{
        pos = mystr[c];
        cout<<pos<<endl;
    }while(pos != -1);
    return 0;
}
