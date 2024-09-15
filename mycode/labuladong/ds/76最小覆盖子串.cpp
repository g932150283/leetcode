#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {

        unordered_map<char, int> needs;
        unordered_map<char, int> windows;
        for (char c : t)
        {
            needs[c]++;
        }
        int start = 0, minLen = INT_MAX;
        int l = 0, r = 0;
        int match = 0;
        while (r < s.size())
        {
            char c = s[r];
            if (needs.count(c))
            {
                windows[c]++;
                if (windows[c] == needs[c])
                {
                    match++;
                }
            }
            r++;
            while (match == needs.size())
            {
                if (r - l < minLen)
                {
                    start = l;
                    minLen = r - l;
                }
                // 移除
                char cc = s[l];
                if (needs.count(cc))
                {
                    windows[cc]--;
                    if (windows[cc] < needs[cc])
                    {
                        match--;
                    }
                }
                l++;
                /* code */
            }

            /* code */
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};