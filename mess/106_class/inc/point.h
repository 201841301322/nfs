#pragma once
#include <iostream>
using namespace std;


class Point
{
private:
    double m_X;
    double m_Y;
public:
    //设置X坐标
    void set_X(double X);
    
    //获取X坐标
    double get_X();
   
    //设置Y坐标
    void set_Y(double Y);
    
    //获取X坐标
    double get_Y();
    
    //设置坐标点
    void set_P(double X, double Y);
    
};