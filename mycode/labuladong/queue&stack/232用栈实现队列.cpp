#include<bits/stdc++.h>

using namespace std;

class MyQueue {
    stack<int> s1, s2;
public:
    MyQueue() {

    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        s2.pop();
    }
    
    int peek() {
        if(s2.empty()){
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
                /* code */
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s2.empty() && s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */