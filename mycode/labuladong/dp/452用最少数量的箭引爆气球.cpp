#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 0){
            return 0;
        }
        sort(points.begin(), points.end(), cmp);
        int count = 1;// 非重叠区间个数
        int end = points[0][1];
        for(auto point : points){
            int start = point[0];
            if(start > end){
                count++;
                end = point[1];
            }
        }
        return count;
    }
};