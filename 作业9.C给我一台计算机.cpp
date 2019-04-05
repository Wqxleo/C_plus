#include <iostream>
using namespace std;
class CPU
{
public:
    CPU(char c)
    {
        m_c = c;
    }
    CPU(const CPU &c)
    {
        m_c = c.m_c;
    }
    ~CPU()
    {

    }
    int getCPU()
    {
       return m_c;
    }
private:
    int m_c;
};
class Memory
{
public:
    Memory(int m)
    {
        m_m = m;
    }
    ~Memory()
    {

    }
    Memory(const Memory &m)
    {
        m_m = m.m_m;
    }
    int getMemory()
    {
        return m_m;
    }
private:
    int m_m;
};
class Computer
{
public:
    Computer(CPU c, Memory m, string n) : m_cpu(c), m_memory(m), m_name(n)
    {

    }
    ~Computer()
    {

    }
    void show()
    {
        cout<<"This is "<<m_name<<"' computer with CPU = "<<m_cpu.getCPU()<<"GHz, memory = "<<m_memory.getMemory()<<"MB."<<endl;
    }
private:
    CPU m_cpu;
    Memory m_memory;
    string m_name;
};
int main()
{
    int c, m;
    string n;
    cin>>c>>m>>n;
    CPU cpu(c);
    Memory mem(m);
    Computer com1(cpu, mem, n);
    cin>>c>>m>>n;
    Computer com2(c, m, n);
    com1.show();
    com2.show();
    return 0;
}
