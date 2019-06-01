#include<thread>
//correct
void threadFunc(const int &m)
{
    //todo
}
void threadFunc(const int m)
{
    //todo
}
void threadFunc(int m)
{
    //todo
}    
//fail
void threadFunc(int &m)
{
    //todo
}    










