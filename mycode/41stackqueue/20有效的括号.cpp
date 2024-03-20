#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0){
            return false;
        }
        stack<char> sc;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                sc.push(')');
            }else if(s[i] == '['){
                sc.push(']');
            }else if(s[i] == '{'){
                sc.push('}');
            }else if(sc.empty() || sc.top() != s[i]){
                return false;
            }else{
                sc.pop();
            }
        }
        return sc.empty();
    }
};