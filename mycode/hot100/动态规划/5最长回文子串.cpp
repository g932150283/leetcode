#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n < 2){
            return s;
        }
        int maxLen = 1;
        int begin = 0;
        // dp[i][j] 表示dp[i-j]是否为回文串
        vector<vector<int>> dp(n, vector<int>(n));
        // 所有长为1为回文串
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }
        for(int l = 2; l <= n; l++){
            for(int i = 0; i < n; i++){
                int j = l + i - 1;
                if(j >= n){
                    break;
                }
                if(s[i] != s[j]){
                    dp[i][j] = false;
                }else{
                    if(j - i < 3){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if(dp[i][j] && j - i + 1 > maxLen){
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
            
        }
        return s.substr(begin, maxLen);

    }
};