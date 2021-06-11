#include <iostream>
#include <string>
#include"circle.h"
#include"point.h"
using namespace std;
const double PI=3.14;

//对象的初始化和清理
//1.构造函数 进行初始化操作
class Person
{
    //1.1.构造函数
    //没有返回值，不用写void
    //函数名与类名相同
    //构造函数可以有参数，可以发生重载
    //创建对象的时候，构造函数会自动调用，而且只调用一次
    public:
    Person()
    {
        cout<<"Person 构造函数的调用"<<endl;
    }

    //2.析构函数 进行清理的操作
    //没有返回值 不用写 void
    //函数名和类名相同 在名前加~
    //析构函数不可以有参数，不可以发生重载
    //对象在销毁前 会自动调用析构函数，而且只会调用一次
    ~Person()
    {
        cout<<"Person 析构函数的调用"<<endl;
    }
};


//构造函数的分类及调用
//分类
// 按照参数分类 无参构造和有参构造
class PPerson
{
    public:
    int age;
    PPerson()
    {
        cout<<"PPerson 无参构造函数的调用"<<endl;

    }

     PPerson(int a)
    {
        age=a;
        cout<<"PPerson 有参构造函数的调用"<<endl;

    }
     //拷贝构造函数
     PPerson(const PPerson &p)
    {
        age=p.age;
        cout<<"PPerson 拷贝构造函数的调用"<<endl;

    }

    ~PPerson()
    {
        cout<<"PPerson 析构函数的调用"<<endl;

    }
};
// 
int main()
{
    //调用
    //1.括号法
//    PPerson p1;//默认构造函数调用
//    PPerson p2(10);//有参构造函数
//    PPerson p3(p2);//拷贝构造函数
    //注意事项
    //调用默认构造函数时候，不要加()，不然会认为是函数声明
    //
    // cout<<"p2的年龄"<<p2.age<<endl;
    // cout<<"p3的年龄"<<p3.age<<endl;
    
    //2.显示法
    // PPerson p1;//默
    // PPerson p2 = PPerson(10);//有
    // PPerson p3 = PPerson(p2);//考
    
    //3.隐式转换法
    // PPerson p4 = 10;//有
    // PPerson p5 = p4;//拷
    
    return 0;
}
