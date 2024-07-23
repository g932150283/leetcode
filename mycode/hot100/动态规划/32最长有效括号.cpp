#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        {
            int left = 0;
            int right = 0;
            for (auto it = s.begin(); it != s.end(); ++it) {
                if (*it == '(') {
                    ++left;
                } else if (*it == ')') {
                    ++right;
                }
                if (left < right) {
                    left = 0;
                    right = 0;
                } else if (left == right) {
                    ans = max(ans, 2 * right);
                }
            }
        }
        {
            int right = 0;
            int left = 0;
            for (auto rit = s.rbegin(); rit != s.rend(); ++rit) {
                if (*rit == ')') {
                    ++right;
                } else if (*rit == '(') {
                    ++left;
                }
                if (left > right) {
                    right = 0;
                    left = 0;
                } else if (left == right) {
                    ans = max(ans, 2 * left);
                }
            }
        }
        return ans;
    }
};
