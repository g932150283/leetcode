#include<bits/stdc++.h>

using namespace std;

/*
教学过程中，教练示范一次，学员跟做三次。
该过程被混乱剪辑后，记录于数组 actions，
其中 actions[i] 表示做出该动作的人员编号。
请返回教练的编号。
*/
class Solution {
public:
    int trainingPlan(vector<int>& actions) {
        int res[32] = {0}; 
        int m = 1;
        int sum = 0;
        for(int i = 0; i < 32; i++){
            for(auto ac : actions){
                if(m & ac){
                    res[i]++;
                }
            } 
            res[i] = res[i] % 3;
            sum = sum + res[i] * m;
            m = m << 1;
        }

        return sum;
        
    }
};

int main(){
    vector<int> v = {2, 2, 2, 1};
    Solution* s = new Solution();
    cout << s->trainingPlan(v);
    return 0;
}