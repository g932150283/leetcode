
#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.

 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：[[5,4,11,2],[5,8,4,5]]
*/
class Solution {
public:
    vector<vector<int> > res;

    vector<int> path;

    vector<vector<int>> pathTarget(TreeNode* root, int target) {
        recur(root, target);
        return res;
    }

    void recur(TreeNode* root, int target){
        if(!root){
            return;
        }
        path.push_back(root->val);
        target -= root->val;
        if(!root->left && !root->right && !target){
            res.push_back(path);
        }
        recur(root->left, target);
        recur(root->right, target);
        path.pop_back();
    }


};

int main(){

    return 0;
}