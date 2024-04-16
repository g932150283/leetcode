#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        string s;
        cin >> s;
        vector<int> nums(n);
        vector<int> window(n - 2);
        for(int i = 0; i < n; i++){
            nums[i] = s[i] - 'A' + 1;
        }
        for(int i = 0; i <= nums.size() - 3;i++){
            window[i] = abs(nums[i] - 16) + abs(nums[i + 1] -4) + abs(nums[i + 2] - 4);
        }
        vector<int> vec;
        int wlen = (n - 2) % 3;
        if(wlen == 0){
            int i = 0;
            while (i < n - 2)
            {
                /* code */
            }
        }
        for(int i = 0; i < nums.size() - 2; i++){
            int index = i;
            int res = 0;
            while (index <= ((window.size() / 3) - 1) * 3 + i)
            {
                int sum = min(min(nums[index], nums[index + 1]), nums[index + 2]);
                res += sum;
                /* code */
            }
            vec.push_back(res);

            
            

        }
    }
}
// 64 位输出请用 printf("%lld")