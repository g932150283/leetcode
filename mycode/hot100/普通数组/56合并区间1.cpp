#include <bits/stdc++.h>
using namespace std;

class Solution {
    static bool cmp(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // sort(intervals.begin(), intervals.end(), [](auto a, auto b){
        //     return a[0] < b[0]; 
        // });
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;
        for(auto interval : intervals){
            if(res.size() == 0){
                res.push_back(interval);
                continue;
            }
            if(res.back()[1] >= interval[0]){
                res.back()[1] = max(res.back()[1], interval[1]);
                continue;
            }
            res.push_back(interval);
        }
        return res;

        
    }
};
