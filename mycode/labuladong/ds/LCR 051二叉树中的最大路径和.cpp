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
class Solution {
    int res = INT_MIN;
    int oneSide(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int l = max(0, oneSide(root->left));
        int r = max(0, oneSide(root->right));
        res = max(res, root->val + l + r);
        return max(l, r) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        oneSide(root);
        return res;
    }
};