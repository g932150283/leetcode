#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ss = s + s;
        ss = ss.substr(1, ss.size() - 2);
        if(ss.find(s) != string::npos){
            return true;
        }
        return false;
    }
};

int main(){

    Solution* s = new Solution();
    s->repeatedSubstringPattern("aba");

    return 0;
}