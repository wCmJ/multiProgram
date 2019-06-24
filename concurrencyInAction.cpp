#include<iostream>
#include<thread>
class background_task{
public:
    void operator()()
    {
        //
    }
};

background_task f;
std::thread t(f);//correct
//temp variable
std::thread t1(background_task());//error
std::thread t2((background_task()));//correct
std::thread t3{background_task()};//correct
std::thread t4([]{
    //dosomething
});//correct
//必须在thread对象销毁之前确定线程是joined还是detached，否则程序会终止。thread的析构函数会调用std::terminate()
//若使用detach(),不等待线程，必须保证线程结束之前，数据的有效性
//使用join().可以确保局部变量在线程完成后，才被销毁。清理线程相关的存储部分，thread对象将不再与已经完成的线程有任何关联。只能对一个线程使用一次join()。
//RAII（resource acquisition is intialization）
//局部对象被逆序销毁








