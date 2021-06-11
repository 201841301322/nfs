#include <iostream>
#include <string>
using namespace std;
const double PI=3.14;


class Cube
{
    private:
        double m_H;//高
        double m_L;//长
        double m_W;//宽
    public:
        //设置长
        void setL(double L)
        {
            m_L=L;
        }
        //获取长
        double getL()
        {
            return m_L;
        }
        //设置宽
        void setW(double W)
        {
            m_W=W;
        }
        //获取宽
        double getW()
        {
            return m_W;
        }
        //设置长
        void setH(double H)
        {
            m_H=H;
        }
        //获取长
        double getH()
        {
            return m_H;
        }
        //获取体积
        double getV()
        {
            return m_H*m_L*m_W;
        }
        //获取面积
        double getArea()
        {
            return 2*m_W*m_H+2*m_W*m_L+2*m_H*m_L;
        }
        //成员函数判断两个立方体是否相等
        bool isSameByClass(Cube &c)
        {
            if(m_L==c.getL()&&m_W==c.getW()&&m_H==c.getH())
            {   cout<<"成员函数判断是相等的"<<endl;
                return true;
            }
            else
            {   cout<<"成员函数判断是不相等的"<<endl;
                return false;
            }
        }
    
};

bool isSame(Cube &c1,Cube &c2)
{
    if(c1.getL()==c2.getL()&&c1.getW()==c2.getW()&&c1.getH()==c2.getH())
    {
        cout<<"全局函数判断是相等的"<<endl;
        return true;
    }
    else
    {   
        cout<<"全局函数判断是不相等的"<<endl;
        return false;
    }
}
int main()
{
    Cube c1;
    c1.setH(10);
    c1.setL(10);
    c1.setW(10);
    cout<<c1.getArea()<<endl;
    cout<<c1.getV()<<endl;
    Cube c2;
    c2.setL(10);
    c2.setW(10);
    c2.setH(10);
    isSame(c1,c2);
    c1.isSameByClass(c2);
}
