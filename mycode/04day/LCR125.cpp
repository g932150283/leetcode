#include<bits/stdc++.h>

using namespace std;

class CQueue {
public:
    stack<int> s1, s2;
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(!s2.empty()){
            int tmp = s2.top();
            s2.pop();
            return tmp;
        }
        if (s1.empty())
            return -1;
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
            /* code */
        }

        int tmp = s2.top();
        s2.pop();
        return tmp;
        
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */