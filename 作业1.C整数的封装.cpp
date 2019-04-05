#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
class Integer
{
public:
    //当函数比较简单时，用内联函数
    Integer(int data)
    {
        m_data = data;
    }
    Integer(char*, int);
    int getValue()
    {
        return m_data;
    }

private:
    char m_str[100];
    int m_data,m_radix;

};

//函数体比较复杂时，不要用内联函数
Integer::Integer(char *str, int radix)
{
    //一行代码做一件事
    int l;
    int i;
    int flag = 1;
    int sum = 0;
    strcpy(m_str,str);
    m_radix = radix;
    l = strlen(m_str);
    for(i = l-1; i >= 0; i--)
    {
        if(m_str[i] >= '0' && m_str[i] <= '9')
        {
            m_str[i] = m_str[i] - '0';
        }
        else
        {
            if(m_str[i] >= 'A' && m_str[i] <= 'Z')
            {
                m_str[i] = m_str[i] - 'A' + 'a' + 10;
            }
            else
            m_str[i] = m_str[i] - 'a' + 10;
        }

        sum +=  m_str[i]*flag;
        flag *= m_radix;

    }
    m_data = sum;
}
int main()
{
    char str[100];
    int numOfData, numOfStr;
    int data, i, radix;

    cin>>numOfData;
    for (i = 0; i < numOfData; i++)
    {
        cin>>data;
        Integer anInteger(data);
        cout<<anInteger.getValue()<<endl;
    }

    cin>>numOfStr;
    for (i = 0; i < numOfStr; i++)
    {
        cin>>str>>radix;
        Integer anInteger(str,radix);
        cout<<anInteger.getValue()<<endl;
    }
    return 0;
}
