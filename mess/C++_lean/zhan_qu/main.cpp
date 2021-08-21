#include <iostream>
using namespace std;
/*
//栈区数据注意事项 --不要返回局部变量的地址
//栈区的数据由编译器管理开辟和释放
//利用new把数据开辟到堆区
int* func()
{
    //栈区a
    int a=10;
    //堆区new
    int *p=new int(10);//局部变量
    return p;
}

int main()
{
    //在堆区开辟数据
    int *p =func();
    cout<<*p<<endl;
}

*/
//--------------------------------------------------------------
//引用：给变量起别名,本质是指针常量  int * const ref=&a;
//语法：数据类型 &别名=原名
/*注意：
    1.引用必修要初始化
    2.引用一旦初始化后，不可以改变
    3.
*/

//引用函数 代替指针
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;

}
//引用做函数的返回值
//1.不要返回局部变量的引用
int& test01()
{
    static int a =10;
    return a;
}
int main()
{
    // int a=20;
    // int b=100;
    // swap(a,b);
    // cout<<a<<endl;
    // cout<<b<<endl;
//-------------------------------------------------
    // int &a=test01();
    // cout<<a<<endl;
    // test01()=1000;//如果函数作为左值，那么必须返回引用
    // cout<<a<<endl;
//---------------------------------------------------
    int a=10;
    int b=20;
    int        *             const                        p=&a;
    *p=30;
    cout<<*p<<endl;

}
