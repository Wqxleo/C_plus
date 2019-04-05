#include <iostream>
#include <iomanip>
using namespace std;
class Double
{
public:
    Double(int x = 0, int y = 0)
    {
        m_x = x;
        m_y = y;
    }
    void show()
    {
        cout<<m_x<<"."<<m_y;
    }
    double getdouble()
    {
        double sum;
        double tmp = m_y;
        int t = m_y;
        tmp *= 0.1;
        while(t /10 > 0)
        {
            tmp *= 0.1;
            t /= 10;
        }
        sum = m_x + tmp;
        return sum;
    }
    void setX(int x)
    {
        m_x = x;
    }
    void setY(int y)
    {
        m_y = y;
    }
    ~Double()
    {

    }
private:
    int m_x;
    int m_y;
};
class DoubleArray
{
public:
    DoubleArray(int *a, int *b, int n)
    {
        int i;
        num = n;
        data = new Double[num];
        for(i = 0; i < num; i++)
        {
            data[i].setX(a[i]);
            data[i].setY(b[i]);
        }
    }
    void show()//方法：显示所有的元素。输出时，数组元素两两之间用1个空格隔开，且前后无多余空格，最后输出一个换行符。
    {
        int i;
        data[0].show();
        for(i = 1; i < num; i++)
        {
            cout<<" ";
            data[i].show();
        }
        cout<<endl;
    }
    DoubleArray& sortArray(bool a)//：对数组进行排序。当参数值为true时，排序结果为递增序；否则为递减序。
    {
        int i,j;
        Double tap;
        if(a)
        {
            for(i = 1; i < num; i++)
            {
                for(j = 0; j < num - i; j++)
                {
                    if(data[j].getdouble() > data[j+1].getdouble())
                    {
                        tap = data[j];
                        data[j] = data[j+1];
                        data[j+1] = tap;
                    }
                }
            }
        }
        else
        {
            for(i = 1; i < num; i++)
            {
                for(j = 0; j < num - i; j++)
                {
                    if(data[j].getdouble() < data[j+1].getdouble())
                    {
                        tap = data[j];
                        data[j] = data[j+1];
                        data[j+1] = tap;
                    }
                }
            }
        }
        return *this;
    }
    DoubleArray& insertAtPos(Double a, int n)//：在第2个参数指定的位置插入第1个参数给定的对象。注意：对于长度为n的数组，合法的插入位置为[0,n]。
    {
        if(n >= 0 && n <= num)
        {
            int i;
            Double *tmp = new Double[num];
            for(i = 0; i < num; i++)
            {
                tmp[i] = data[i];
            }
            data = new Double[num + 1];
            for(i = 0; i < n; i++)
            {
                data[i] = tmp[i];
            }
            num++;
            data[n] = a;
            for(i = n+1; i < num; i++)
            {
                data[i] = tmp[i-1];
            }
            delete []tmp;//释放临时对象
            return *this;

        }
    }
    DoubleArray& deleteADouble(Double d)//：删除数组中所有与给定参数相等的元素。
    {
        int i,j;
        for(i = 0; i < num; i++)
        {
            if(data[i].getdouble() == d.getdouble())
            {
                for(j = i; j < num; j++)
                {
                    data[j] = data[j+1];
                }
                num--;
            }
        }
        return *this;
    }
private:
    Double *data;
    int num;
};
int main()
{
    Double one, two(10,10);
    int num, i, a, b, c, *iPart, *dPart;
    cin>>num;
    iPart = new int[num];
    dPart = new int[num];
    for (i = 0; i < num; i++)
    {
        cin>>iPart[i]>>dPart[i];
    }
    DoubleArray test(iPart, dPart, num);
    test.show();
    test.sortArray(true).show();
    test.sortArray(false).show();
    cin>>num;
    for (i = 0; i < num; i++)
    {
        cin>>a>>b>>c;
        test.insertAtPos(Double(a, b), c);
    }
    test.show();
    test.deleteADouble(Double()).show();
    delete[] iPart;
    delete[] dPart;
    return 0;
}
