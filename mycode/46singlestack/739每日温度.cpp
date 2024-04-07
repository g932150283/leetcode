#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // 一眼单调栈
        stack<int> s;
        vector<int> res(temperatures.size());
        s.push(0);
        for(int i = 1; i < temperatures.size(); i++){
            if(temperatures[i] <= temperatures[s.top()]){
                s.push(i);
            }else{
                while (!s.empty() && temperatures[i] > temperatures[s.top()])
                {
                    res[s.top()] = i - s.top();
                    s.pop();
                    /* code */
                }
                s.push(i);                
            }
        }
        return res;
    }
};