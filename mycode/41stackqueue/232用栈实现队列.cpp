#include<bits/stdc++.h>

using namespace std;

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
//使用两个栈实现先入先出队列
    MyQueue() {

    }
    // 将元素 x 推到队列的末尾
    void push(int x) {
        s1.push(x);
    }
    //从队列的开头移除并返回元素
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }            
        }
        int res = s2.top();
        s2.pop();
        return res;
    }
    // 返回队列开头的元素
    int peek() {
        int front = this->pop();
        s2.push(front);
        return front;

    }
    //如果队列为空，返回 true ；否则，返回 false
    bool empty() {
        return s1.empty() && s2.empty();
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