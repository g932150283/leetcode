#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dpi0 = 0;
        int dpi1 = INT_MIN;
        for(int i = 0; i < prices.size(); i++){
            dpi0 = max(dpi0, dpi1 + prices[i]);
            dpi1 = max(dpi1, -prices[i]);
        }
        return dpi0;
    }
};