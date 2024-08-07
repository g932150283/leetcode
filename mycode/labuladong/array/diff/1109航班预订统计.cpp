#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // 初值为0差分，免构建
        vector<int> diff(n);
        for(auto booking : bookings){
            int startIndex = booking[0] - 1;
            int endIndex = booking[1] - 1;
            int inc = booking[2];
            diff[startIndex] += inc;
            if(endIndex + 1 < n){
                diff[endIndex + 1] -= inc;
            }
        }
        vector<int> res(n);
        res[0] = diff[0];
        for(int i = 0; i < n; i++){
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
};