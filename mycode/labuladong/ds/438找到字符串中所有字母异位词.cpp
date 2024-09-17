#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string t)
    {
        vector<int> res;
        unordered_map<char, int> needs;
        unordered_map<char, int> windows;
        for (char c : t)
        {

            needs[c]++;
        }
        int l = 0, r = 0;
        int start = 0, minLen = INT_MAX;
        int match = 0;
        while (r < s.size())
        {
            char c = s[r];
            if (needs.count(c))
            {
                windows[c]++;
                if (needs[c] == windows[c])
                {
                    match++;
                }
            }
            r++;
            while (match == needs.size())
            {
                // cout << r << " " << l << endl;
                // cout << needs.size() << endl;
                if (r - l == t.size())
                {

                    res.push_back(l);
                }
                char cc = s[l];
                if (needs.count(cc))
                {
                    windows[cc]--;
                    if (windows[cc] < needs[cc])
                    {
                        // cout << cc << endl;
                        match--;
                    }
                }
                l++;
            }

            /* code */
        }
        return res;
    }
};