#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        // if(n == 0){
        //     return 1;
        // }
        // if(n == 1){
        //     return 1;
        // }
        // if(n == 2){
        //     return 2;
        // }
        // return climbStairs(n - 1) + climbStairs(n - 2);
        vector<int> dp(46);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};