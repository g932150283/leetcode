/*
给定一个括号字符串如：”[{()}]”，判断字符串中括号是否合法，出现的括号为 [ ] { } ( )
*/

#include<bits/stdc++.h>

using namespace std;

int getAns(const string& s){
    if(s.size() == 0){
        return 1;
    }
    stack<char> st;
    for(char ch:s){
        if(ch == ')'){
            if(!st.empty() && st.top() == '('){
                st.pop();
            }else{
                return 0;
            }
        }else if(ch == '}'){
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }else{
                return 0;
            }
        }else if(ch == ']'){
            if(!st.empty() && st.top() == '['){
                st.pop();
            }else{
                return 0;
            }
        }else{
            st.push(ch);
        }
    }
    if(!st.empty()){
        return 0;
    }else{
        return 1;
    }
}


int main(){
    string s1 = "[{()}]";
    string s2 = "[{()}]]";
    string s3 = "[[{()}]]";

    cout << getAns(s1) << endl;
    cout << getAns(s2) << endl;
    cout << getAns(s3) << endl;

}