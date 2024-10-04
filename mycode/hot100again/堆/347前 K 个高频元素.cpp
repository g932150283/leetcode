#include<bits/stdc++.h>

using namespace std;
struct myComparison
{
    bool operator()(pair<int, int>& p1, pair<int, int>& p2){
        return p1.second > p2.second;
    }
    /* data */
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 大顶堆
        priority_queue<pair<int, int>, vector<pair<int, int>> ,myComparison> que;
        unordered_map<int, int> umap;
        vector<int> res;
        for(int num : nums){
            umap[num]++;
        }
        for(auto a : umap){
            que.push(a);
            if(que.size() > k){
                que.pop();
            }
        }
        while (!que.empty())
        {
            res.push_back(que.top().first);
            que.pop();
            /* code */
        }
        return res;
        

    }
};