#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> trainingPlan(vector<int>& actions) {
        int i = 0, j = actions.size() - 1;
        while (i < j){
            while (i < j && ((actions[i] & 1) == 1)){
                i++;
            }
            while (i < j && ((actions[j] & 1) == 0)){
                j--;
            }
            swap(actions[i], actions[j]);
        }
        return actions;
        
    }
};


int main(){

    vector<int> v = {1,2,3,4,5};
    Solution* s = new Solution();
    s->trainingPlan(v);
    return 0;
}