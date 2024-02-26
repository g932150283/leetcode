#include<bits/stdc++.h>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s1;
    int min = 0;
    MinStack() {

    }
    
    void push(int x) {
        // 当前值与最小值的差值
        if(s1.empty()){
            min = x;
            s1.push(0);
            return;
        }
        int compare = x - min;
        if(compare < 0){
            min = x;
        }
        s1.push(compare);
        
    }
    
    void pop() {
        if(s1.top() > 0){
            s1.pop();
            return;
        }
        min = s1.top() - min;
        s1.pop();

    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){

    MinStack m;
    m.push(2);
    cout << "arr = 2, " 
         << "stakc = " << m.top() 
         << ", min = " << m.getMin() << endl;
    m.push(1);
    cout << "arr = 1, " 
         << "stakc = " << m.top() 
         << ", min = " << m.getMin() << endl;
    m.push(3);
    cout << "arr = 3, " 
         << "stakc = " << m.top() 
         << ", min = " << m.getMin() << endl;
    m.push(0);
    cout << "arr = 0, " 
         << "stakc = " << m.top() 
         << ", min = " << m.getMin() << endl;
    return 0;
}