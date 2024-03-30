#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    // 身高从大到小排（身高相同k小的站前面）
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort (people.begin(), people.end(), cmp);
        vector<vector<int>> queue(people.size());

        for(int i = 0; i < people.size(); i++){
            int position = people[i][1];
            queue.insert(queue.begin() + position, people[i]);
        }
        return queue;

    }
};


int main(){
    vector<vector<int>> v = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};


    return 0;
}