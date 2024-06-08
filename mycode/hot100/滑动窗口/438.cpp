#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string t)
    {
        // unordered_map<char, int> need, window;
        // for (char c : t) need[c]++;

        // int left = 0, right = 0;
        // int valid = 0;
        // vector<int> res; // 记录结果
        // while (right < s.size()) {
        //     char c = s[right];
        //     right++;
        //     // 进行窗口内数据的一系列更新
        //     if (need.count(c)) {
        //         window[c]++;
        //         if (window[c] == need[c])
        //             valid++;
        //     }
        //     // 判断左侧窗口是否要收缩
        //     while (right - left >= t.size()) {
        //         // 当窗口符合条件时，把起始索引加入 res
        //         if (valid == need.size())
        //             res.push_back(left);
        //         char d = s[left];
        //         left++;
        //         // 进行窗口内数据的一系列更新
        //         if (need.count(d)) {
        //             if (window[d] == need[d])
        //                 valid--;
        //             window[d]--;
        //         }
        //     }
        // }
        // return res;
        unordered_map<char, int> need, window;
        for (char ch : t)
        {
            need[ch]++;
        }
        vector<int> res;
        int left = 0, right = 0;
        int valid = 0;
        while (right < s.size())
        {
            char ch = s[right];
            right++;
            if (need[ch] > 0)
            {
                window[ch]++;
                if (window[ch] == need[ch])
                {
                    valid++;
                }
            }
            while (right - left >= t.size())
            {
                if (valid == t.size())
                {
                    res.push_back(left);
                }
                char cha = s[left];
                left++;
                if (need[cha] > 0)
                {
                    if (window[cha] == need[cha])
                    {
                        valid--;
                    }
                    window[cha]--;
                }
                /* code */
            }
            
            /* code */
        }
        return res;
    }
};