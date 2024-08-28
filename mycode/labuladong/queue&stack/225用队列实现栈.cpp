#include<bits/stdc++.h>

using namespace std;

class MyStack {
    queue<int> q;
    int topNum;
public:
    MyStack() {

    }
    
    void push(int x) {
        q.push(x);
        topNum = x;
    }
    
    int pop() {
        int size = q.size();
        while (size > 2)
        {
            q.push(q.front());
            q.pop();
            /* code */
        }
        topNum = q.front();
        q.push(q.front());
        q.pop();
        int res = q.front();
        q.pop();
        return res;
        
    }
    
    int top() {
        return topNum;
    }
    
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