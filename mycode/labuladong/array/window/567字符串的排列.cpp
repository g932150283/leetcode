#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() > s1.size()){
            return false;
        }
        unordered_map<char, int> needs, window;
        for(char c : s1){
            needs[c]++;
        }
        // 是否包含，不需要起始位置以及长度，只需要valid，最后看valid的值
        int left = 0, right = 0;
        int valid = 0;
        while (right < s2.size())
        {
            char c = s2[right];
            right++;
            if(needs.count(c)){
                window[c]++;
                if(window[c] == needs[c]){
                    valid++;
                }
            }
            if(right - left == s1.size()){
                if(valid == needs.size()){
                    return true;
                }
                // 收缩
                char d = s1[left];
                left--;
                if(needs.count(d)){
                    if(needs[d] == window[d]){
                        valid--;
                    }
                    window[d]--;
                }
            }
            /* code */
        }
        return false;
    }
};