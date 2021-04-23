#include <iostream>
using namespace std;

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