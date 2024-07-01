#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        int num = 0;
        stack<string> str;
        string res = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                num = num * 10 + s[i] - '0';
            }else if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')){
                res += s[i];
            }else if(s[i] == '['){
                nums.push(num);
                num = 0;
                str.push(res);
                res = "";
            }else if(s[i] == ']'){
                for(int j = 0; j < nums.top(); j++){
                    str.top() = str.top() + res;
                }
                nums.pop();
                res = str.top();
                str.pop();
            }
        }
        return res;
    }
};

