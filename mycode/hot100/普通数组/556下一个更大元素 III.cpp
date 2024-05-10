#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int m = s.size();
        if(m <= 1){
            return -1;
        }
        // 先找到最小的数字
        int i = m - 2;
        while (i >= 0)
        {
            if(s[i] < s[i + 1]){
                break;
            }
            i--;
            /* code */
        }

        // i < 0 说明数组递增，已经为最大
        if(i < 0){
            return -1;
        }
        // 找到比s[i] 大的第一个数字
        int j = m - 1;
        while (j > i)
        {
            if(s[j] > s[i]){
                break;
            }
            /* code */
            j--;
        }
        swap(s[i], s[j]);

        reverse(s.begin() + i + 1, s.end());
        long res = stol(s);
        return res > INT_MAX ? -1 : res;
        


        
    }
};