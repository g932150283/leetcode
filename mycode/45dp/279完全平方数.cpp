#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        // dp[j] 和为j的完全平方数的最小数量
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i * i <= n; i++){
            for(int j = i*i; j <= n; j++){
                dp[j] = min(dp[j - i * i] + 1, dp[j]);
            }
        }
        return dp[n];


    }
};