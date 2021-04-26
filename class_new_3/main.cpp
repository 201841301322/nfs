#include <iostream>
#include <string>
using namespace std;
const double PI=3.14;

class Point
{
private:
    double m_X;
    double m_Y;
public:
    //设置X坐标
    void set_X(double X)
    {
        m_X=X;
    }
    //获取X坐标
    double get_X()
    {
        return m_X;
    }
    //设置Y坐标
    void set_Y(double Y)
    {
        m_Y=Y;
    }
    //获取X坐标
    double get_Y()
    {
        return m_Y;
    }
    //设置坐标点
    void set_P(double X, double Y)
    {
        set_X(X);
        set_Y(Y);
    }
};


class Circle
{
private:
    double r;
    Point cir;
public:
    //设置圆心
    void set_Center(double X, double Y)
    {
        cir.set_X(X);
        cir.set_Y(Y);
    }
    //获取圆心
    Point get_Center()
    {
        return cir;
    }
    //设置半径
    void set_Rad(double R)
    {
        r=R;
    }
    //获取半径
    double get_Rad()
    {
        return r;
    }
};


void if_point_cir(Point p,Circle c)
{
    double distan=(p.get_X()-c.get_Center().get_X())*(p.get_X()-c.get_Center().get_X())+(p.get_Y()-c.get_Center().get_Y())*(p.get_Y()-c.get_Center().get_Y());
    double r=c.get_Rad();
    if(r*r<distan)
    {
        cout<<"点在圆外"<<endl;
    }
    else if(r*r>distan)
    {
        cout<<"点在圆内"<<endl;
    }
    else
    {
        cout<<"点在圆上"<<endl;
    }
}
int main()
{
    Point p;
    Circle c;
    c.set_Center(10,0);
    c.set_Rad(10);
    p.set_P(10,10.1);
    if_point_cir(p,c);
    
}
