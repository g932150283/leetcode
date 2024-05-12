#include <bits/stdc++.h>
using namespace std;

struct Box
{
    int length, width, height;
    Box(int l, int w, int h) : length(l), width(w), height(h){}


    /* data */
};




bool static cmp(Box b1, Box b2){
    if(b1.length < b2.length){
        return true;
    }else{
        return b1.width < b2.width;
    }
}

class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        vector<Box> things;
        for(int i = 0; i < box.size(); i++){
            things.push_back(Box(box[i][0], box[i][1], box[i][2]));
        }
        sort(things.begin(), things.end(), cmp);
        vector<int> dp(box.size(), 0);
        int maxv = 0;
        for(int i = 1; i < box.size(); i++){
            int fjmax = 0;
            for(int j = 0; j < i; j++){
                
                if(things[i].length < things[j].length && things[i].width < things[j].width){
                    fjmax = max(fjmax,dp[j]);
                }
            }
            dp[i] = fjmax+dp[i];
            maxv = max(maxv,dp[i]);
        }
        return maxv;
    }
};


int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> length;
        vector<int> width;
        vector<int> height;
        vector<Box> things;
        for(int i = 0; i < n; i++){
            int a,b,c;
            cin >> a >> b >> c;
            // length.push_back(a);
            // width.push_back(b);
            // height.push_back(c);
            things.push_back(Box(a, b, c));
        }
        sort(things.begin(), things.end(), cmp);
        vector<pair<int, int>> t;
        // dp[j] 以j为底最大值
        vector<int> dp(n, 0);
        int maxH = 0;
        for(int i = n - 1; i >= 0; i--){
            for(int j = i - 1; j >= 0; j--){
            }
        }
    }
}
// 64 位输出请用 printf("%lld")