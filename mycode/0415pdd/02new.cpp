#include<bits/stdc++.h>
using namespace std;


bool isjump(vector<int>& nums){
    if(nums.size() == 1){
        return false;
    }
    for(int i = 0; i < nums.size() - 1;i++){
        if(nums[i] == nums[i + 1]){
            return false;
        }
    }
    return true;
}




int main() {
    /*(
        4
        1 3 5 3
    )*/
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        int res = 0;
        for(int i = 2; i <= nums.size(); i++){
            for(int j = 0; j <= nums.size() - i; j++){
                vector<int> path(nums.begin() + j, nums.begin() + j + i);
                if(isjump(path)){
                    for(int p : path){
                        res += p;
                    }
                }
            }
        }
        
        cout << res << endl;
    }

}
// 64 位输出请用 printf("%lld")