#include <bits/stdc++.h>

using namespace std;


class Solution {
    string getPalindrome(string s, int l, int r){
        while (l >= 0 && r < s.length() && s[l] == s[r])
        {
            l--;
            r++;
            /* code */
        }
        return s.substr(l + 1, r - l - 1);
        
    }
public:
    string longestPalindrome(string s) {
        string res = "";
        for(int i = 0; i < s.length(); i++){
            string s1 = getPalindrome(s, i, i);
            string s2 = getPalindrome(s, i, i + 1);
            if(res.length() < s1.length()){
                res = s1;
            }
            if(res.length() < s2.length()){
                res = s2;
            }
        }
        return res;

    }
};