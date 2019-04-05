#include <iostream>
#include <vector>
using namespace std;
class Operate
{
public:
    Operate(int x, int y) : arr(x,y)
    {
    }
    ~Operate()
    {

    }
    void Modify()
    {
        int x,y;
        cin>>x>>y;
        arr[x-1] = y;
    }
    void Insert()
    {
        int a,b,c;
        cin >> a >> b >> c;
        arr.insert(arr.begin() + a - 1, arr.begin() + b - 1, arr.begin() + c);
    }
    void Erase()
    {
        int a,b;
        cin >> a >> b;
        arr.erase(arr.begin() + a - 1, arr.begin() + b);
    }
    void Print()
    {
        int a,b;
        cin >> a >> b;
        cout << "[" << a << "]" << ":" << arr[a - 1];
        for(int i = a; i < b; i++)
            cout << " [" << i + 1 << "]" << ":" << arr[i];
        cout << endl;
    }
private:
    vector<int> arr;
};
int main()
{
    string operation;
    int x,y,z;
    cin>>operation>>x>>y;
    Operate arr(x,y);
    while(cin >> operation)
    {
        if(operation == "Modify")
        {
            arr.Modify();
        }
        else if(operation == "Insert")

        {
            arr.Insert();
        }
        else if(operation == "Erase")
        {
            arr.Erase();
        }
        else if(operation == "Print")
        {
            arr.Print();
        }
    }
    return 0;
}
