#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        for(int i = 3; i <= n; i++){
            for(int j = 1; j <= i / 2; j++){

                dp[i] = max(max(dp[i - j] * j, (i - j) * j), dp[i]);
            }
        }
        return dp[n];
    }
};