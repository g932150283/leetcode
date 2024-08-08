#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int left = 0, right = 0;
        int valid = 0;
        int res = 0;
        while (right < s.size())
        {
            char c = s[right];
            right++;
            window[c]++;

            // 收缩
            if(window[c] > 1){
                char d = s[left];
                left++;
                window[c]--;
            }
            res = max(res, right - left);
            /* code */
        }
        return res;
        
    }
};