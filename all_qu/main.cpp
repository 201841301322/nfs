#include <iostream>
using namespace std;

//全局变量
int g_a=10;
const int c_g_a=10;
int main()
{
    //创建普通局部变量
    int a = 10;
    int b = 10;
    cout<<"局部变量a地址："<<&a<<endl;
    cout<<"局部变量b地址："<<&b<<endl;
    cout<<"全局变量g_a地址："<<&g_a<<endl;

    //静态变量
    static int s_a = 10;
    cout<<"静态变量s_a地址："<<&s_a<<endl;

    //常量
    //字符串常量
    cout<<"字符串常量地址："<<(long)&"hello world"<<endl;
    //const 修饰的常量
    //const 修饰的全局常量
    cout<<"const 修饰的全局常量c_g_a地址："<<&c_g_a<<endl;
    //const 修饰的局部变量
    const int c_l_a=10; //c-const g-global l-local
    cout<<"const 修饰的局部变量c_l_a地址："<<&c_l_a<<endl;

}