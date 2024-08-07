#include <bits/stdc++.h>

using namespace std;


/*
假设你有一个长度为 n 的数组，初始情况下所有的数字均为 0，你将会被给出 k​​​​​​​ 个更新的操作。

其中，每个操作会被表示为一个三元组：[startIndex, endIndex, inc]，
你需要将子数组 A[startIndex ... endIndex]
（包括 startIndex 和 endIndex）增加 inc。

请你返回 k 次操作后的数组。

示例:

输入: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
输出: [-2,0,3,5,3]
解释:

初始状态:
[0,0,0,0,0]

进行了操作 [1,3,2] 后的状态:
[0,2,2,2,0]

进行了操作 [2,4,3] 后的状态:
[0,2,5,5,3]

进行了操作 [0,2,-2] 后的状态:
[-2,0,3,5,3]

*/

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> diff(length);
        // 构建diff(全0免构建)
        // 发生改变
        // 复原
        for(auto update : updates){
            int startIndex = update[0];
            int endIndex = update[1];
            int inc = update[2];
            diff[startIndex] += inc;
            if(endIndex + 1 < length){
                diff[endIndex + 1] -= inc;
            }
        }
        // 复原
        vector<int> res(length);
        res[0] = diff[0];
        for(int i = 1; i < length; i++){
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
};

int main(){
    // [[1,3,2],[2,4,3],[0,2,-2]]
    vector<vector<int>> v1 = {{1,3,2}, {2,4,3}, {0,2,-2}};
    Solution* s = new Solution();
    auto res = s->getModifiedArray(5, v1);
    for(auto i : res){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}