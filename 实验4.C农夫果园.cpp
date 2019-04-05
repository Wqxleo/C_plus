#include <iostream>
using namespace std;
class Fruit
{
public:
    Fruit(char c)
    {
        numOffruit++;
        cout<<"The "<<numOffruit<<"th fruit is created."<<endl;
    }
    ~Fruit()
    {

    }
protected:
    char name;
    static int numOffruit;
};
class Apple : public Fruit
{
public:
    Apple(char c, int w) : Fruit(c),weight(w)
    {
        numOfapple++;
        cout<<"The "<<numOfapple<<"th apple is created."<<endl;
    }
    ~Apple()
    {

    }
private:
    int weight;
    static int numOfapple;
};
class Peach : public Fruit
{
public:
    Peach(char n, int w) : Fruit(n), weight(w)
    {
        numOfpeach++;
        cout<<"The "<<numOfpeach<<"th peach is created."<<endl;
    }
    ~Peach()
    {

    }
private:
    int weight;
    static int numOfpeach;
};
int Fruit :: numOffruit = 0;
int Apple :: numOfapple = 0;
int Peach :: numOfpeach = 0;
int main()
{
    int n,i,numa,nump,weight;
    numa = nump = weight = 0;
    char c;
    int w;
    cin>>n;
    Apple **apples = new Apple*[n];
    Peach **peachs = new Peach*[n];
    for(i = 0; i < n; i++)
    {
        cin>>c>>w;
        weight += w;
        if(c == 'a')
        {
            apples[numa] = new Apple(c,w);
            numa++;
        }
        if(c == 'p')
        {
            peachs[nump] = new Peach(c,w);
            nump++;
        }
    }
    for(i = 0; i < numa; i++)
        delete apples[i];
    for(i = 0; i < nump; i++)
        delete peachs[i];
    delete []apples;
    delete []peachs;
    cout<<"There are "<<n<<" fruits, including "<<numa<<" apples and "<<nump<<" peaches. Their total weights is "<<weight<<"."<<endl;
}
