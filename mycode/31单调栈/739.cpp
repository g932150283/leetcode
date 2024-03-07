#include<bits/stdc++.h>

using namespace std;
// 单调栈作用，存放之前遍历过的元素
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> res(temperatures.size(), 0);
        s.emplace(0);
        for(int i = 1; i < temperatures.size(); i++){
            while(!s.empty() && temperatures[i] > temperatures[s.top()]){
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.emplace(i);
            
        }
        return res;
    }
};

int main(){


    vector<int> v = {73,74,75,71,69,72,76,73};
    Solution* s = new Solution();
    s->dailyTemperatures(v);
    return 0;
}