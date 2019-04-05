#include <iostream>
#include <vector>
#include <stack>
#include <iterator>
using namespace std;
class Operation
{
public:
    void inputData()
    {
        int tmp;
        while(1)
        {
            cin>>tmp;
            if(tmp != 0)
                data.push_back(tmp);
            else
                break;
        }
    }
    void inputOpers()
    {
        char c;
        while(1)
        {
            cin>>c;
            if(c != 'e' && c != 'E')
                opers.push_back(c);
            else
                break;
        }
    }
    void showResult()
    {
        vector<int>::iterator itr1;
        vector<char>::iterator itr2;
        itr1 = data.begin();
        int flag1 = 0;
        int flag2 = 0;
//        for(itr2 = opers.begin(); itr2 != opers.end(); itr2++)
//        {
//            if((*itr2 == 'i' || *itr2 == 'I') && itr1 != data.end())
//            {
//                itr1++;
//                flag2 = 1;
//            }
//        }
//        if(flag2 == 0)
//        {
//            cout<<"The pop sequence is: Empty."<<endl;
//        }

            itr1 = data.begin();
            cout<<"The pop sequence is: ";
            for(itr2 = opers.begin(); itr2 != opers.end(); itr2++)
            {
                if((*itr2 == 'i' || *itr2 == 'I') && itr1 != data.end())
                {
                    iStack.push(*itr1);
                    itr1++;
                }
                if((*itr2 == 'o' || *itr2 == 'O') && !iStack.empty() && flag1 != 0)
                {
                    cout<<" "<<iStack.top();
                    iStack.pop();

                }
                if((*itr2 == 'o' || *itr2 == 'O') && !iStack.empty() && flag1 == 0)
                {
                    cout<<iStack.top();
                    iStack.pop();
                    flag1 = 1;
                    flag2 = 1;
                }
            }
            if(flag2 == 0)
                cout<<"Empty.";
            cout<<endl;
    }
    void clearData()
    {
        data.clear();
        opers.clear();
        while(!iStack.empty())
        {
            iStack.pop();
        }
    }
private:
    vector<int> data;
    stack<int> iStack;
    vector<char> opers;
    vector<int> result;
};
int main()
{
    Operation myOp;
    int cases;
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        myOp.clearData();
        myOp.inputData();
        myOp.inputOpers();
        myOp.showResult();
    }
    return 0;
}




//#include <iostream>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
//class Operation {
//private:
//    vector<int> data;
//    stack<int> iStack;
//    vector<char> opers;
//    vector<int> result;
//public:
//    void inputData()//fine
//    {
//        int x;
//        cin >> x;
//        while (x != 0) {
//            data.push_back(x);
//            cin >> x;
//        }
//    }
//
//    void inputOpers() {
//        char x;
//        cin >> x;
//        int countin = 0;
//        while (x != 'e' && x != 'E') {
//            if (x == 'i' || x == 'I' || x == 'o' || x == 'O') {
//                opers.push_back(x);
//                if (x == 'i' || x == 'I') countin++;
//            }
//            cin >> x;
//        }
//        if (countin != 0) {
//            while (opers[0] == 'o' || opers[0] == 'O') {
//                opers.erase(opers.begin());
//                if (*opers.begin() == 'i' || *opers.begin() == 'I')
//                    break;
//            }
//            vector<char>::iterator count;
//            for (count = opers.begin(); count != opers.end(); count++) {
//                if (*count == 'i' || *count == 'I')//Take a attion to iter's use way.
//                {
//                    iStack.push(*data.begin());
//                    data.erase(data.begin());
//                }
//                else if (countin != 0) {
//                    result.push_back(iStack.top());
//                    iStack.pop();
//                    countin--;
//                }
//            }
//        }
//    }
//
//    void showResult() {
//        if (result.empty()) { cout << "The pop sequence is: Empty." << endl; }
//        else {
//            cout << "The pop sequence is: ";
//            while (!result.empty()) {
//                cout << *result.begin() << ' ';
//                result.erase(result.begin());
//            }
//            cout << endl;
//        }
//    }
//
//    void clearData()//fine
//    {
//        data.clear();
//        while (!iStack.empty())//bug,nothing
//            iStack.pop();
//        opers.clear();
//        result.clear();
//    }
//};
//
//int main() {
//    freopen("in.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
//    Operation myOp;
//    int cases;
//    cin >> cases;
//    for (int i = 0; i < cases; i++) {
//        myOp.clearData();
//        myOp.inputData();
//        myOp.inputOpers();
//        myOp.showResult();
//    }
//    return 0;
//}
//
