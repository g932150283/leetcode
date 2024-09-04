#include<bits/stdc++.h>

using namespace std;



class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0){
            return 0;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        int end = intervals[0][1];
        int count = 1;// 非重叠个数
        for(auto interval : intervals){
            int start = interval[0];
            if(start >= end){
                count++;
                end = interval[1];
            }else{
                continue;
            }
        }
        return intervals.size() - count;
    }
};