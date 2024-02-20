#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool verifyTreeOrder(vector<int>& postorder) {
        return recur(postorder, 0, postorder.size()-1);
    }

    bool recur(vector<int>& postorder, int i, int j){
        if(i >= j){
            return true;
        }
        // 找到小于根节点的
        int p = i;
        while (postorder[p] < postorder[j]){
            p++;
        }
        int m = p;
        while (postorder[p] > postorder[j]){
            p++;
        }
        return p == j && recur(postorder, i, m - 1) && recur(postorder, m, j - 1);        
    }
};

int main(){

    vector<int> v1 = {4,9,6,5,8};
    vector<int> v2 = {4,6,5,9,8};
    vector<int> v3 = {4,5,9,8,6};
    Solution* s;
    cout << s->verifyTreeOrder(v1) << endl;
    cout << s->verifyTreeOrder(v2) << endl;
    cout << s->verifyTreeOrder(v3) << endl;

}

