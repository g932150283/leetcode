#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int takeAttendance(vector<int>& records) {
        int l = 0;
        int r = records.size() - 1;

        while (l <= r){
            int mid = (r - l) / 2 + l;
            // [l, mid, r]
            if(records[mid] == mid){
                l = mid + 1;
            }else{
                // records[mid] != mid
                r = mid - 1;
            }
        }
        return l;
    }
};



int main(){
    vector<int> v1 = {0, 1, 2, 3, 5};
    Solution* s = new Solution();
    // cout << s->countTarget(v1, 4) << endl;
    // cout << s->countTarget(v2, 6) << endl;
    cout << s->takeAttendance(v1) << endl;

    return 0;
}