#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int low = INT_MAX;
        // int res = 0;
        // for(int i = 0; i < prices.size(); i++){
        //     low = min(low, prices[i]);
        //     res = max(res, prices[i] - low);
        // }
        // return res;
        if(prices.size() == 0){
            return 0;
        }

        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < prices.size(); i++){
            // 持有股票时，手里的钱，越多越好
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            // 股票卖出时，手里的钱，越多越好
            dp[i][1] = max(dp[i - 1][1], dp[i][0] + prices[i]);
        }
        return dp[prices.size() - 1][1];
    }
};