#include<bits/stdc++.h>

using namespace std;

// typedef pair<int, int> PAIR;  


// struct CmpByValue {  
//   bool operator()(const PAIR& lhs, const PAIR& rhs) {  
//     return lhs.second > rhs.second;  
//   }  
// };


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> map;
        priority_queue<pair<int, int>> pque;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }

        // vector<PAIR> orderByValue(map.begin(), map.end()); 
        // sort(orderByValue.begin(), orderByValue.end(), CmpByValue());  
        // for(int i = 0; i < k; i++){
        //     res.push_back(orderByValue[i].first);
        // }
        for(auto it = map.begin(); it != map.end(); it++){
            pque.push(pair<int, int>(it->second, it->first));
        }
        while (k--)
        {
            res.push_back(pque.top().second);
            /* code */
            pque.pop();
        }
        

        return res;


    }
};