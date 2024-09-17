#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> windows;
        int l = 0, r = 0;
        int res = 0;
        while (r < s.size())
        {
            char c = s[r];
            windows[c]++;
            r++;
            while (windows[c] > 1)
            {
                char cc = s[l];
                windows[cc]--;
                l++;
                /* code */
            }
            res = max(res, r - l);
            
            /* code */
        }
        return res;
        
        
    }
};