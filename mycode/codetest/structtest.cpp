#include <bits/stdc++.h>

using namespace std;

struct Perfect
{
    const static int crazy_bird = 2017;
    void Print() { printf("crazy_bird= %d\n", crazy_bird); }
};
struct World
{
    Perfect perfect;
    virtual void Print() { printf("crazy_bird= %d\n", perfect.crazy_bird); }
};
// 令Perfect *p = NULL，World *w = NULL，则p->Print() 和 w->Print() 输出分别为：