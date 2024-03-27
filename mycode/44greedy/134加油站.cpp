

#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // // 局部最优推出全局最优
        // int start = 0;
        // int curSum  = 0;
        // int totalSum = 0;

        // for(int i = 0; i < gas.size(); i++){
        //     curSum += gas[i] - cost[i];
        //     totalSum += gas[i] - cost[i];
        //     if(curSum < 0){
        //         start = i + 1;
        //         curSum = 0;
        //     }
        // }
        // if(totalSum < 0){
        //     return -1;
        // }
        // return start;

        int curSum = 0;
        int min = INT_MAX;
        for(int i = 0; i < gas.size(); i++){
            int rest = gas[i] - cost[i];
            curSum += rest;
            if(curSum < min){
                min = curSum;
            }
        }
        if(curSum < 0){
            return -1;
        }
        if(min > 0){
            return 0;
        }

        for (int i = gas.size() - 1; i >= 0; i--) {
            int rest = gas[i] - cost[i];
            min += rest;
            if (min >= 0) {
                return i;
            }
        }

        return -1;
    }
};