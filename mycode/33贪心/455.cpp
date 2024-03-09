#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0;
        int gptr = 0;
        int sptr = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while (sptr < s.size() && gptr < g.size())
        {
            if(g[gptr] <= s[sptr]){
                res++;
                gptr++;
                sptr++;
            }else{
                sptr++;
            }
            
            /* code */
        }
        return res;       
    }
};

int main(){

    vector<int> g = {10,9,8,7};
    vector<int> s = {5,6,7,8};
    Solution* s1 = new Solution();
    int i = s1->findContentChildren(g, s);
}