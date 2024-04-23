#include<bits/stdc++.h>

using namespace std;



class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        for(char ch : p){
            need[ch]++;
        }
        int left = 0, right = 0;
        int valid = 0;
        vector<int> res;
        while (right < s.size())
        {
            char ch = s[right];
            right++;
            if(need.count(ch)){
                window[ch]++;
                if(window[ch] == need[ch]){
                    valid++;
                }
            }
            while (right - left >= p.size())
            {
                if(valid == need.size()){
                    res.push_back(left);
                }
                char d = s[left];
                left++;
                if(need.count(d)){
                    if(window[d] == need[d]){
                        valid--;
                    }
                    window[d]--;
                }
                /* code */
            }
            

            /* code */
        }
         return res;
    }
};