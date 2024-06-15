#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (cin >> s)
    {
        string ss = "";
        for(int i = 1; i < s.size() - 1; i++){
            ss += s[i];
        }
        // cout << ss << endl;
        if(ss.size() < 4){
            cout << "[]" << endl;
        }
        if(ss.size() == 4){
            string an = "";
            for(int i = 0; i < 4; i++){
                if(i == 3){
                    an += ss[i];
                    break;
                }
                an += ss[i];
                an += '.';
            }
            cout << '[' << an << ']' << endl;
        }

        // vector<int> dou;
        // for(int i = 0; i < ss.size(); i++){
        //     if(ss[i] == ','){
        //         dou.push_back(i);
        //     }
        // }
        // vector<int> nums;
        // nums.push_back(stoi(ss.substr(0, dou[0])));
        // for(int i = 0; i < dou.size(); i++){
        //     if(i == dou.size() - 1){
        //         nums.push_back(stoi(ss.substr(dou[i] + 1, ss.size())));
        //         continue;
        //     }
        //     nums.push_back(stoi(ss.substr(dou[i] + 1, dou[i+1] - dou[i] - 1)));
        // }
        // // for(int i : nums){
        // //     cout << i << endl;
        // // }
        // int res = 0;
        // int l = 0;
        // int r = nums.size() - 1;
        // while (l < r)
        // {
        //     res = max(res, min(nums[l], nums[r]) * (r - l));
        //     if(nums[l] > nums[r]){
        //         r--;
        //     }else{
        //         l++;
        //     }
        //     /* code */
        // }
        // cout << res << endl;
        
    }
    
   
    
    
}
// 64 位输出请用 printf("%lld")