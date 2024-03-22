#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> s;
        for(string str : tokens){
            if(str == "+" || str == "-" || str == "*" || str == "/"){
                long long num1 = s.top();
                s.pop();
                long long num2 = s.top();
                s.pop();
                if(str == "+"){
                    s.push(num2 + num1);
                }
                if(str == "-"){
                    s.push(num2 - num1);
                }
                if(str == "*"){
                    s.push(num2 * num1);
                }
                if(str == "/"){
                    s.push(num2 / num1);
                }
            }else{
                s.push(stoll(str));
            }
        }
        return s.top();
    }
};