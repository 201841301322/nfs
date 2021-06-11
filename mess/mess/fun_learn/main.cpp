#include <iostream>
using namespace std;

//函数重载
//可以让函数名相同，提高复用性
int func(int a=10,int b=20,int c=30)
{

    return a+b+c;
}
int func(int a=10)
{

    return a;
}
int func(int a,char b )
{

    return a+b;
}

int main()
{
   cout<< func(10,60)<<endl;
}
