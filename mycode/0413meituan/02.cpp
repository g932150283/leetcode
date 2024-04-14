#include <bits/stdc++.h>
using namespace std;

static bool cmp(int a, int b) {
    return abs(a) < abs(b);
}


int main() {
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        vector<int> nums(a);
        for(int i = 0; i < a; i++){
            cin >> nums[i];
        }
        
        sort(nums.begin(), nums.end(), cmp);
        int res = 0;
        for(int num : nums){
            if(b >= abs(num)){
                res++;
                b = b - abs(num);
            }
        }
        return res;
    }
}
// 64 位输出请用 printf("%lld")