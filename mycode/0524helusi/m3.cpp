/*
去除数组中所有重复元素
*/

#include<bits/stdc++.h>

using namespace std;

void getAns(vector<int>& nums){
    vector<int> tmp;
    for(int n : nums){
        tmp.push_back(n);
    }
    nums.clear();
    unordered_map<int, int> umap;
    for(int n : tmp){
        umap[n]++;
    }
    for(int n : tmp){
        if(umap[n] > 1){
            continue;
        }
        nums.push_back(n);
    }
}



int main(){
    vector<int> v = {1,2,2,3,5};
    getAns(v);
    for(int n : v){
        cout << n << " ";
    }
    cout << endl;
    return 0;
}