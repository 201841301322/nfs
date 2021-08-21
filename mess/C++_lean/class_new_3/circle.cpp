#include "circle.h"
void Circle::set_Center(double X, double Y)
    {
        cir.set_X(X);
        cir.set_Y(Y);
    }
    //获取圆心
    Point Circle::get_Center()
    {
        return cir;
    }
    //设置半径
    void Circle::set_Rad(double R)
    {
        r=R;
    }
    //获取半径
    double Circle::get_Rad()
    {
        return r;
    }