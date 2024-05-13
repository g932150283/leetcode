#include <bits/stdc++.h>

using namespace std;

class Solution
{
    bool getValid(const char &c, const char &b)
    {
        if (c == '(' && b == ')')
        {
            return true;
        }
        else if (c == '{' && b == '}')
        {
            return true;
        }
        else if (c == '[' && b == ']')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:
    bool isValid(string s)
    {
        stack<char> st;
        for (char ch : s)
        {
            if (ch == '(' || ch == '[' || ch == '{')
            {
                st.push(ch);
            }
            else
            {
                if(st.empty()){
                    return false;
                }
                if (getValid(st.top(), ch))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }else{
            return false;
        }
        
    }
};