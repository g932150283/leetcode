#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSales(vector<int>& sales) {
        // int res = sales[0];
        // for(int i = 1; i < sales.size(); i++){
        //     if(res < sales[i]){
        //         res = sales[i];
        //     if(sales[i - 1] > 0){
        //         sales[i] = sales[i] + sales[i - 1];
        //     }
        // }
        // return res;
        vector<int> dp;
        dp[0] = sales[0];
        for(int i = 1; i < sales.size(); i++){
            if(dp[i - 1] <= 0){
                dp[i] = sales[i];
            }else{
                dp[i] = dp[i - 1] + sales[i];
            }
        }
        return dp.back();
    }
};