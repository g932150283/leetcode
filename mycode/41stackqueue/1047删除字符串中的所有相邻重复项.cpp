#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(char ch : s){
            if(!st.empty() && st.top() == ch){
                st.pop();
            }else{
                st.push(ch);
            }
        }
        string res;
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
            /* code */
        }
        reverse(res.begin(), res.end());
        return res;
    }

    
};