#include<bits/stdc++.h>
using namespace std;

// 去重
unordered_set<int> uset;
vector<vector<int> > res;
vector<int> path;
int result;

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

void backtracking(vector<int>& nums, int index, int num){
    if(path.size() != 0 && find(res.begin(), res.end(), path) == res.end() && isjump(path)){
        res.push_back(path);
        for(int p : path){
            cout << p << " ";
            result += p;
        }
        cout << endl;
        // for(int p : path){
        //     result += p;
        // }
    }

    for(int i = index; i <= nums.size() - num; i++){
        path.clear();
        for(int j = i; j < i + num; j++){
            path.push_back(nums[j]);
        }
        backtracking(nums, i + 1, num);
        
        
    }
}



int main() {
    /*(
        4
        1 3 5 3
    )*/
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> nums(n);
        if(n == 1){
            cout << 0 << endl;
        }else{
            for(int i = 0; i < n; i++){
                cin >> nums[i];
            }
        
            for(int i = 2; i <= nums.size(); i++){
                backtracking(nums, 0, i);
            }
            cout << result << endl;
        }
        
    }
}
// 64 位输出请用 printf("%lld")

