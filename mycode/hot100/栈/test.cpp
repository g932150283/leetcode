#include <bits/stdc++.h>

using namespace std;

class A
{
    virtual void fun1(){}
};
class B
{
    virtual void fun2(){}
};
class C : public A, public B
{
};
int main()
{
    C c;
    A *pA = &c;
    B *pB = &c;
    C *pC = &c;
    return 0;
}