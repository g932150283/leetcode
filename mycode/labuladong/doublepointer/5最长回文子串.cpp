#include <bits/stdc++.h>

using namespace std;


class Solution {
    string getRes(string s, int l, int r){
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            l++;
            r--;
            /* code */
        }
        return s.substr(l + 1, r - l - 1);
        
    }
public:
    string longestPalindrome(string s) {    
        string res;
        if(s.size() == 0){
            return res;
        }
        for(int i = 0; i < s.size(); i++){
            string s1 = getRes(s, i, i);
            string s2 = getRes(s, i, i + 1);
            res = res.size() > s1.size() ? res : s1;
            res = res.size() > s2.size() ? res : s2;
        }
        return res;

    }
};