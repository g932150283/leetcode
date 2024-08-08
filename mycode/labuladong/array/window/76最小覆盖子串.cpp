#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> needs, window;
        for(char c : t){
            needs[c]++;
        }
        int left = 0, right = 0;
        int valid = 0;
        int start = 0, len = INT_MAX;
        while (right < s.size())
        {
            // 扩大
            char c = s[right];
            right++;
            if(needs.count(c)){
                window[c]++;
                if(window[c] == needs[c]){
                    valid++;
                }
            }
            // 收缩
            while (valid == needs.size())
            {
                if(right - left < len){
                    start = left;
                    len = right - left;
                }
                // 开始收缩
                char d = s[left];
                left++;
                if(needs.count(d)){
                    if(needs[d] == window[d]){
                        valid--;
                    }
                    window[d]--;
                }
                /* code */
            }
            /* code */
        }
        return len == INT_MAX ? "" : s.substr(start, len);
        
    }
};