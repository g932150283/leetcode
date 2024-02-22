#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countTarget(vector<int>& scores, int target) {
        // 找第一个大于target和最后一个小于target，两下标插值-1即为所求结果
        if(scores.size() == 0) return 0;
        int up = upper(scores, target);
        int low = lower(scores, target);
        if(up < 0 || low < 0 || scores[up] != target || scores[low] != target) return 0;
        return abs(upper(scores, target) - lower(scores, target)) + 1;
        
    }

    int upper(vector<int>& scores, int target){
        // 第一个等于target
        int l = 0;
        int r = scores.size() - 1;
        if(scores[r] < target){
            return -1;
        }
        while (l < r){
            int mid = (r - l) / 2 + l;
            // [l, mid, r]
            if(scores[mid] > target){
                r = mid;
            }else if(scores[mid] == target){
                l = mid + 1;
            }else{
                // scores[mid] < target
                l = mid + 1;
            }
        }
        if(l - 1 >= 0 && scores[l - 1] == target){
            return l-1;
        }
        return l;
    }

    int lower(vector<int>& scores, int target){
        // 最后一个等于target
        int l = 0;
        int r = scores.size() - 1;
        if(scores[l] > target){
            return -1;
        }
        while (l < r){
            int mid = (r - l + 1) / 2 + l;
            // [l, mid, r]
            if(scores[mid] > target){
                r = mid - 1;
            }else if(scores[mid] == target){
                r = mid - 1;
            }else{
                // scores[mid] < target
                l = mid;
            }
        }
        if(l + 1 < scores.size() && scores[l + 1] == target){
            return l+1;
        }
        return l;
    }
};




int main(){
    vector<int> v1 = {2, 2, 3, 4, 4, 4, 5, 6, 6, 8};
    vector<int> v2 = {1, 2, 3, 5, 7, 9};
    vector<int> v = {2,2};
    Solution* s = new Solution();
    // cout << s->countTarget(v1, 4) << endl;
    // cout << s->countTarget(v2, 6) << endl;
    cout << s->countTarget(v, 2) << endl;

    return 0;
}