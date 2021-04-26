#include <iostream>
#include <string>
using namespace std;
const double PI=3.14;
//设计一个圆类，求圆的周长
//圆求周长的公式：2*pi*半径
//class 代表设计一个类，类后面紧跟着的就是类名称

class Circle
{
public://公共权限
    int m_r;
    double calculateZC()
    {
        return 2*PI*m_r;
    }
};

//学生类
class Student
{
public://公告权限
    //类中的属性和行为 我们统一称为 成员
    //属性 成员属性 成员变量
    //行为 成员函数 成员方法
    
    //属性
    string m_Name;
    string m_Id;
    //方法
    void showStudent()
    {
        cout<<"名字："<<m_Name<<"   学号:"<<m_Id<<endl;
    }
    //设定名字
    void setName(string name)
    {
        m_Name=name;
    }
    void setId(string id)
    {
        m_Id=id;
    }
};


//访问权限
//三种
//公共权限 public    成员   类内可以访问 类外可以访问
//保护权限 protected 成员   类内可以访问 类外不可访问   儿子可以访问父亲中的保护内容
//私有权限 private   成员   类内可以访问 类外不可访问   儿子不可访问父亲私有的内容
class Person
{
    public://公共权限
        string m_Name;
        void func()
        {
         m_Name="张三";
         m_Car="拖拉机";
         m_Password="123456";   
        }
    protected://保护权限
        string m_Car;
    private://私有权限
        string m_Password;

    
};


//成员属性设置为私有
//1.可以自己控制读写权限
//2.对于写可以检测数据的有效性
class PPerson
{
    private:
        string m_name;
        int m_age;
        string m_lover;

    public:
        //写姓名
        void setName(string name)
        {
            m_name=name;
        }
        //获取姓名
        string getName()
        {
            return m_name;
        }  

        int getAge()
        {
            //m_age=18;
            return m_age;
        }
        void setAge(int age)
        {
            if(age<0||age>150)
            {
                m_age=0;
                cout<<"输入年龄错误,默认为0"<<endl;
                return;
            }
            m_age=age;
        }
        void setLover(string lover)
        {
            m_lover=lover;
        }
};


int main()
{
    //    Circle c1;
    //    c1.m_r=10;
    //    cout<<"圆的周长："<<c1.calculateZC()<<endl;
    //---------------------------------------------------------------
    // Student s1,s2;
    // s1.setName("张三3");
    // s1.setId("201841301322");
    // s2.setName("李四");
    // s2.setId("201841301323");
    // s1.showStudent();
    // s2.showStudent();
    //-------------------------------------------------------------------
    // Person p1;
    // p1.func();
    // p1.m_Name="李四";
    //-----------------------------------------------
    PPerson p1;
    p1.setName("zs");
    p1.setLover("cjk");
    p1.setAge(122);
    cout<<p1.getName()<<endl;
    cout<<p1.getAge()<<endl;

}
