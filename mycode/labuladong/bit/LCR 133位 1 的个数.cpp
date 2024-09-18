#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int res = 0;
        while (n != 0)
        {
            res++;
            n = n & (n - 1);
            /* code */
        }
        return res;
        
    }
};