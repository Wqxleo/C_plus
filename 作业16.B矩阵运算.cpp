#include <iostream>
using namespace std;
class Matrix
{
public:
    Matrix()
    {
        flag = 1;
        m = 0;
        n = 0;
    }
    Matrix operator+(Matrix &M)
    {
        if(m == M.m && n == M.n)
        {
            Matrix tmp;
            tmp.flag = 0;
            tmp.m = m;
            tmp.n = n;
            int i,j;
            tmp.arr = new int*[m];
            for(i = 0; i < m; i++)
            {
                tmp.arr[i] = new int[n];
            }
            for(i = 0; i < m; i++)
            {
                for(j = 0; j < n; j++)
                {
                    tmp.arr[i][j] = arr[i][j] + M.arr[i][j];
                }
            }
            return tmp;
        }
        else
        {
            Matrix tmp;
            return tmp;
        }



    }
    Matrix operator*(Matrix &M)
    {
        if(n == M.m)
        {
            Matrix tmp;
            tmp.flag = 0;
            tmp.m = m;
            tmp.n = M.n;
            int i,j,k;
            tmp.arr = new int*[m];
            for(i = 0; i < m; i++)
            {
                tmp.arr[i] = new int[M.n];
            }
            for(i = 0; i < m; i++)
            {
                for(j = 0; j < M.n; j++)
                {
                    tmp.arr[i][j] = 0;
                    for(k = 0; k < n; k++)
                    {
                        tmp.arr[i][j] += arr[i][k]*M.arr[k][j];
                    }
                }
            }
            return tmp;
        }
        else
        {
            Matrix tmp;
            return tmp;
        }

    }
    friend istream& operator>>(istream& is, Matrix &M);
    friend ostream& operator<<(ostream& os, const Matrix &M);

private:
    int m;
    int n;
    int **arr;
    int flag;
};
istream& operator>>(istream& is, Matrix &M)
{
    int i,j;
    is>>M.m>>M.n;
    M.arr = new int*[M.m];
    for(i = 0; i < M.m; i++)
    {
        M.arr[i] = new int[M.n];
    }
    for(i = 0; i < M.m; i++)
    {
        for(j = 0; j < M.n; j++)
        {
            is>>M.arr[i][j];
        }
    }
    return is;
}
ostream& operator<<(ostream& os,const Matrix &M)
{
    if(M.flag == 1)
    {
        os<<"Error"<<endl;
    }
    else
    {
        int i,j;
        for(i = 0; i < M.m; i++)
        {
            for(j = 0; j < M.n; j++)
            {
                if(j != 0)
                {
                    os<<" ";
                }
                os<<M.arr[i][j];
            }
            os<<endl;
        }
    }

    return os;
}
int main()
{
    int cases, i;
    cin>>cases;
    for (i = 0; i < cases; i++)
    {
        Matrix A, B, C, D;
        cin>>A>>B;
        C = A + B;
        D = A * B;
        cout<<"Case "<<i + 1<<":"<<endl;
        cout<<C<<endl;
        cout<<D;
    }
    return 0;
}
