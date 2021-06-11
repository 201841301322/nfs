#include "point.h"



//设置X坐标
    void Point::set_X(double X)
    {
        m_X=X;
    }
    //获取X坐标
    double Point::get_X()
    {
        return m_X;
    }
    //设置Y坐标
    void Point::set_Y(double Y)
    {
        m_Y=Y;
    }
    //获取X坐标
    double Point::get_Y()
    {
        return m_Y;
    }
    //设置坐标点
    void Point::set_P(double X, double Y)
    {
        set_X(X);
        set_Y(Y);
    }