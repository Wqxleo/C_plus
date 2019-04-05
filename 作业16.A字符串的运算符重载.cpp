#include <iostream>
using namespace std;
class Character
{
public:
    char operator+(int value)
    {
        char tmp;
        value %= 26;
        tmp = ch+value;
        if(tmp > 'z')
            tmp -= 26;
        else if(tmp < 'a')
        tmp += 26;
    }
    char operator-(int value)
    {
        char tmp;
        value %= 26;
        tmp = ch-value;
        if(tmp > 'z')
            tmp -= 26;
        else if(tmp < 'a')
        tmp += 26;
    }
    friend istream& operator>>(istream& is, Character &c);
    friend ostream& operator<<(ostream& os, const Character &c);
private:
    char ch;

};
istream& operator>>(istream& is, Character &c)
{
    is>>c.ch;
    return is;
}
ostream& operator<<(ostream& os,const Character &c)
{
    os<<c.ch;
    return os;
}
int main()
{
    int cases, data;
    Character ch;
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        cin>>ch;
        cin>>data;
        cout<<(ch + data)<<" "<<(ch - data)<<endl;
    }
}
