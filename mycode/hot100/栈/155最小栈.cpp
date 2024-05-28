#include<bits/stdc++.h>

using namespace std;

class MinStack {
    stack<int> st;
    stack<int> minst;
public:
    MinStack() {

    }
    
    void push(int val) {
        if(!minst.empty()){
            if(val <= minst.top()){
                minst.push(val);
            }
        }else{
            minst.push(val);
        }
        st.push(val);

    }
    
    void pop() {
        if(st.empty()){
            return;
        }else{
            if(st.top() == minst.top()){
                st.pop();
                minst.pop();
            }else{
                st.pop();
            }
        }
    }
    
    int top() {
        if(!st.empty()){
            return st.top();
        }
        return 0;
    }
    
    int getMin() {
        if(!minst.empty()){
            return minst.top();
        }
        return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){

    MinStack* m = new MinStack();
    m->push(2);
    m->push(0);
    m->push(3);
    m->push(0);
    m->getMin();
    m->pop();
    m->getMin();
    m->top();
    m->getMin();
    return 0;
}