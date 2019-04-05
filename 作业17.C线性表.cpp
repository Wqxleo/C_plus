#include <iostream>
using namespace std;
class MyList
{
public:
    MyList(int _Len)
    {
        len = _Len;
        elements = new int[len];
        curLen = 0;
    }
    void append(int d)
    {
        elements[curLen] = d;
        curLen++;
    }
    void insert(int p, int d)
    {
        int *tmp = new int[len];
        int i;
        for(i = 0;i < p;i++)
        {
            tmp[i] = elements[i];
        }
        tmp[p] = d;
        curLen++;
        for(i = p +1; i < curLen; i++)
        {
            tmp[i] = elements[i-1];
        }
        delete [] elements;
        elements = tmp;

    }
    void erase(int p)
    {
        int *tmp = new int[len];
        int i;
        for(i = 0;i < p;i++)
        {
            tmp[i] = elements[i];
        }
        for(i = p +1; i < curLen; i++)
        {
            tmp[i-1] = elements[i];
        }
        curLen--;
        delete [] elements;
        elements = tmp;
    }
    void set(int p, int d)
    {
        elements[p] = d;
    }
    void show()
    {
        int i;
        for(i = 0; i < curLen; i++)
        {
            if(i != 0)
                cout<<" ";
            cout<<elements[i];
        }
        cout<<endl;
    }
private:
    int *elements;
    int len;
    int curLen;

};
int main()
{
    int cases, len, data, pos;
    char op;
    cin>>len;
    MyList myList(len);
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        cin>>op;
        switch (op)
        {
        case 'A':
            cin>>data;
            myList.append(data);
            break;
        case 'I':
            cin>>pos>>data;
            myList.insert(pos, data);
            break;
        case 'E':
            cin>>pos;
            myList.erase(pos);
            break;
        case 'S':
            cin>>pos>>data;
            myList.set(pos, data);
        }
        myList.show();
    }
    return 0;
}
