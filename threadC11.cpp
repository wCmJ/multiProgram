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

//single instance
class myCAS
{
  private:
    myCAS(){}
    static mutex m_mutex;
    static myCAS* m_instance;
  public:
    static myCAS* getInstance()
    {
        if(m_instance == NULL)
        {
            lock_guard<mutex> lg(m_mutex);
            if(m_instance == NULL)
            {
                m_instance = new myCAS();
                static CG cg;
            }
        }
        return m_instance;
    }
    class CG{
      public:
        ~CG(){
            if(m_instance)
            {
                delete m_instance;
                m_instance = NULL;
            }
        }
    };
};

mutex g_mutex;
g_mutex.lock();
g_mutex.unlock();

lock_guard<mutex> lg(g_mutex);

g_mutex.lock();
lock_guard<mutex> lg(g_mutex,adopt_lock);

g_mutex.lock();
unique_lock<mutex> ul(g_mutex, adopt_lock);

unique_lock<mutex> ul(g_mutex, try_to_lock);
if(ul.owns_lock())//get lock
{
    //todo
}
else
{
    //todo   
}

unique_lock<mutex> ul(g_mutex, defer_lock);
//do something
ul.lock();
//do something
ul.unlock();
if(ul.try_lock())
{
    //do   
}











