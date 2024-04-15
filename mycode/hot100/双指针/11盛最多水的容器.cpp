#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int max_area = 0;
        while (l < r)
        {
            if(height[l] < height[r]){
                max_area = max(max_area, height[l] * (r - l));
                l++;
            }else{
                max_area = max(max_area, height[r] * (r - l));
                r--;
            }
            /* code */
        }
        return max_area;
        
    }
};