#include <iostream>
#include <iomanip>
using namespace std;
class Book
{
public:
    Book(string name, double price)
    {
        m_name = name;
        m_price = price;
        cout<<"A book "<<name<<" is created."<<endl;
    }
    Book()
    {
        cout<<"A default book is created."<<endl;
    }
    Book(const Book &a)
    {
        m_name = a.m_name;
        m_price = a.m_price;
    }
    string getName()
    {
        return m_name;
    }
    double getPrice()
    {
        return m_price;
    }
    void setName(string name)
    {
        m_name = name;
    }
    void setPrice(double price)
    {
        m_price = price;
    }
    ~Book()
    {
        cout<<"A book "<<m_name<<" is erased."<<endl;
    }
private:
    string m_name;
    double m_price;
};
int main()
{
    Book books[4]={Book("C++", 42.0)};
    string tmp;
    double sum, price;
    int i;
    for (i = 0; i < 3; i++)
    {
        cin>>tmp>>price;
        books[i + 1].setName(tmp);
        books[i + 1].setPrice(price);
    }
    sum = 0;
    for (i = 0; i < 4; i++)
    {
        sum += books[i].getPrice();
    }
    cout<<"The four books are: " << books[0].getName();
    for (i = 1; i < 4; i++)
    {
        cout<<" "<<books[i].getName();
    }
    cout<<endl<<"Their total price is "<<sum<<endl;
    return 0;
}
