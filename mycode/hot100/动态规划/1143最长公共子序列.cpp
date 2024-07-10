#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.length(), m = t.length(), f[2][m + 1];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                f[(i + 1) % 2][j + 1] = s[i] == t[j] ? f[i % 2][j] + 1 :
                                        max(f[i % 2][j + 1], f[(i + 1) % 2][j]);
        return f[n % 2][m];
    }
};
