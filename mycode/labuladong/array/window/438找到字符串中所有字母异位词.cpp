#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string t)
    {
        /*
        输入: s = "cbaebabacd", p = "abc"
        输出: [0,6]
        解释:
        起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
        起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
        */
        vector<int> res;
        if (s.size() < t.size())
        {
            return res;
        }
        unordered_map<char, int> needs, window;
        for (char c : t)
        {
            needs[c]++;
        }
        int left = 0, right = 0;
        int valid = 0;
        while (right < s.size())
        {
            char c = s[right];
            right++;
            if(needs.count(c)){
                window[c]++;
                if(window[c] == needs[c]){
                    valid++;
                }
            }

            if(right - left == t.size()){
                if(valid == needs.size()){
                    res.push_back(left);
                }
                char d = s[left];
                left++;
                if(needs.count(d)){
                    if(window[d] == needs[d]){
                        valid--;
                    }
                    window[d]--;
                }
            }

            /* code */
        }
        return res;
    }
};