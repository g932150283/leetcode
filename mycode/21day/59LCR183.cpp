#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxAltitude(vector<int>& heights, int limit) {
        vector<int> res;
        if(heights.size() == 0 || limit == 0){
            return res; 
        }
        
        deque<int> deque;
        for(int i = 0; i < limit; i++){
            while (!deque.empty() && deque.back() < heights[i]){
                deque.pop_back();
            }
            deque.push_back(heights[i]);
        }
        res.push_back(deque.front());
        // i 右边界
        for(int i = limit; i < heights.size(); i++){
            if(!deque.empty() && deque.front() == heights[i - limit]){
                deque.pop_front();
            }
            while (!deque.empty() && deque.back() < heights[i]){
                deque.pop_back();
            }
            deque.push_back(heights[i]);
            res.push_back(deque.front());
        }
        return res;
    }
};

int main(){

    vector<int> v = {14,2,27,-5,28,13,39};
    Solution* s = new Solution();
    s->maxAltitude(v,3);
    return 0;
}