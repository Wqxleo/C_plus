#include <iostream>
#include <iomanip>
using namespace std;
class Character
{
public:
    Character()
    {
        cout<<"Default constructor is called!"<<endl;
    }
    Character(char a)
    {
        m_ch = a;
        cout<<"Character "<<m_ch<<" is created!"<<endl;
    }
    void setCharacter(char a)
    {
        m_ch = a;
    }
    int getAsciiCode()
    {
        return m_ch;
    }
    char getCharacter()
    {
        return m_ch;
    }
    ~Character()
    {
        cout<<"Character "<<m_ch<<" is erased!"<<endl;
    }
private:
    char m_ch;
};
int main()
{
    char ch;
    Character ch1, ch2('a');
    cin>>ch;
    ch1.setCharacter(ch);
    cout<<"ch1 is "<<ch1.getCharacter()<<" and its ASCII code is "<<ch1.getAsciiCode()<<"."<<endl;
    cout<<"ch2 is "<<ch2.getCharacter()<<" and its ASCII code is "<<ch2.getAsciiCode()<<"."<<endl;
    return 0;
}
