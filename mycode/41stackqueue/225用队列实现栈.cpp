#include<bits/stdc++.h>

using namespace std;
class MyStack {
public:
    queue<int> q;
    MyStack() {}

    //将元素 x 压入栈顶。
    void push(int x) {
        q.push(x);
    }
    //移除并返回栈顶元素。
    int pop() {
        int size = q.size() - 1;
        while (size--)
        {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
            /* code */
        }
        int res = q.front();
        q.pop();
        return res;

        
    }
    //返回栈顶元素。
    int top() {
        
        return q.back();

    }
    //如果栈是空的，返回 true ；否则，返回 false 。
    bool empty() {
        return q.empty();
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