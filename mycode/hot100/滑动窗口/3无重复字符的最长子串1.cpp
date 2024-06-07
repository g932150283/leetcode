#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> umap;
        int res = 0;
        int l = 0;
        for(int i = 0; i < s.size(); i++){
            umap[s[i]]++;
            while (umap[s[i]] > 1)
            {
                umap[s[l]]--;
                l++;
                /* code */
            }
            res = max(res, i - l + 1);
            
        }
        return res;
    }
};