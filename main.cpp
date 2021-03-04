#include <iostream>  //
using namespace std; //代码中的输入输出会方便
int main()
{
    int a; //定义了一个整型变量a,并没有进行初始化
    int b = 10;   //定义了一个整型变量B 给他初始化为10
    a = 11;  //赋值语句 把11赋值给了a
    cout <<"a:"<<a<<endl; // endl代表换行  输出a:变量值后以及变量的值后换行
    cout <<"b: "<<b<<endl;
    int *p = &a;
    cout<<"*p: " <<*p<<endl;
    *p =*p +1;
    cout <<"a："<<a<<endl;

    p = NULL;
    cout<<"*p: " <<p<<endl;
  
    return 0;

}