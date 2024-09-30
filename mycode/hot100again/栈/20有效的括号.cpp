#include <bits/stdc++.h>

using namespace std;

class Solution
{
    char charRight(char c){
        if(c == ')'){
            return '(';
        }
        if(c == ']'){
            return '[';
        }
        return '{';
    }
public:
    bool isValid(string s)
    {
        stack<char> left;
        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                left.push(c);
            }else{
                if(!left.empty() && charRight(c) == left.top()){
                    left.pop();
                }else{
                    return false;
                }
            }
        }
        return left.empty();
        
    }
};