#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return int整型
     */
    int longestValidParentheses(string s) {
        // write code here
        stack<char> sta;
        int res = 0;
        sta.push(s[0]);
        for(int i = 1; i < s.size(); i++){
            if(sta.top() == '(' && s[i] == ')'){
                sta.pop();
                res += 2;
            }else{
                sta.push(s[i]);
            }
        }
        return res;

    }
};