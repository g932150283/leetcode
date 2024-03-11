#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int> > dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        for(int i = 1; i < prices.size(); i++){
            // dp[i][0] 第i天买股票后剩的钱，越多越好
            // 不买-前一天剩的钱  买-前一天不买今天买（手里只能有一只，不买就是前一天剩下的钱，买就是前一天卖出的钱买
            // 因为不卖出没法购买）
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            // dp[i][1] 第i天卖股票后剩的钱，越多越好
            // 不卖-前一天卖出的钱 卖-持有的钱+股票的钱
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return max(dp[prices.size() - 1][0], dp[prices.size() - 1][1]);
    }

    // int maxProfit(vector<int>& prices) {
    //     int result = 0;
    //     for (int i = 1; i < prices.size(); i++) {
    //         result += max(prices[i] - prices[i - 1], 0);
    //     }
    //     return result;
    // }
};


int main(){

    vector<int> v = {7,1,5,3,6,4};
    Solution* s = new Solution();
    s->maxProfit(v);
}