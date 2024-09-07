#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        int dpi0 = 0;
        int dpi1 = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int tmp = dpi0;
            dpi0 = max(dpi0, dpi1 + prices[i]);
            dpi1 = max(dpi1, tmp - prices[i] - fee);
        }
        return dpi0;
    }
};