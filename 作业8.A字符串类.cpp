#include <iostream>
#include <stdio.h>
using namespace std;
class STR
{
public:
    STR()
    {
        str = new char[1];
        str[0] = '\0';
        len = 0;
    }
    STR(const char *s)
    {
        int i,len = 0;
        while(s[len] != '\0')
        {
            len++;
        }
        str = new char[len];
        for(i = 0; i < len; i++)
        {
            str[i] = s[i];
        }
        str[len] = '\0';
    }
    int length()
    {
        int len = 0;
        while(str[len] != '\0')
        {
            len++;
        }
        return len;
    }
    ~STR()
    {
        delete []str;
    }
    void putline()
    {
        puts(str);
    }
private:
    char *str;
    int len;
};
int main()
{
    STR e;
    STR h("Hello World!");
    char s[100001];
    cout << e.length() << " ";
    e.putline();
    cout << h.length() << " ";
    h.putline();
    while (gets(s) != NULL)
    {
        STR str(s);
        cout << str.length() << " ";
        str.putline();
    }
}
