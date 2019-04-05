#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<char> st;
    string str;
    int i;
    int flag;
    while(cin>>str)
    {
        flag = 0;
        for(i = 0; str[i] != '\0'; i++)
        {
            if(str[i] == '(')
                st.push(str[i]);
            else
            {
                if(!st.empty())
                st.pop();
                else
                {
                    flag = 1;
                    break;
                }

            }

        }
        if(st.empty() && flag == 0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
//        while(!st.empty())
//            {
//                st.pop();
//            }
//        str.clear();
    }
    return 0;
}
