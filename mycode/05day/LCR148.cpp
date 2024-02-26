#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool validateBookSequences(vector<int>& putIn, 
                               vector<int>& takeOut) {
        if(putIn.size() == 0) return true;
        stack<int> s;

        int j = 0;
        for(int i = 0; i < putIn.size(); i++){
            s.push(putIn[i]);
            while(!s.empty() && takeOut[j] == s.top()){
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};


int main(){

    vector<int> v1 = {2, 1, 0};
    vector<int> v2 = {1, 2, 0};
    Solution s;
    bool b = s.validateBookSequences(v1, v2);
    cout << b << endl;
    return 0;
}