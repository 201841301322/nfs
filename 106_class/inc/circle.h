#pragma once
#include <iostream>
#include"point.h"
using namespace std;

class Circle
{
private:
    double r;
    Point cir;
public:
    //设置圆心
    void set_Center(double X, double Y);
    
    //获取圆心
    Point get_Center();
    
    //设置半径
    void set_Rad(double R);
    
    //获取半径
    double get_Rad();
    
};
