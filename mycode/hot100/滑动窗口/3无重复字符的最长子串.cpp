#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uset;
        int maxStr = 0;
        if(s.size() == 0){
            return 0;
        }
        int l = 0;
        for(int i = 0; i < s.size(); i++){
            // 找到了
            while (uset.find(s[i]) != uset.end()){
                uset.erase(s[l]);
                l++;
            }
            maxStr = max(maxStr, i - l + 1);
            uset.insert(s[i]);
        }
        return maxStr;
    }
};