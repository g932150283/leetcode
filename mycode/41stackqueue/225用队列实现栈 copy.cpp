#include<bits/stdc++.h>

using namespace std;
class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {}

    //将元素 x 压入栈顶。
    void push(int x) {
        q1.push(x);
    }
    //移除并返回栈顶元素。
    int pop() {
        int size = q1.size() - 1;
        while (size--)
        {
            q2.push(q1.front());
            q1.pop();
            /* code */
        }
        int res = q1.front();
        q1.pop();

        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
            /* code */
        }
        return res;       
        
    }
    //返回栈顶元素。
    int top() {
        return q1.back();

    }
    //如果栈是空的，返回 true ；否则，返回 false 。
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */