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
public:
    int rob(TreeNode* root) {
        auto res = dp(root);
        return max(res[0], res[1]);
    }
    vector<int> dp(TreeNode* root){
        // 0 不抢的最大钱
        // 1   抢的最大钱
        if(root == nullptr){
            return {0, 0};
        }
        vector<int> l = dp(root->left);
        vector<int> r = dp(root->right);
        int doRob = root->val + l[0] + r[0];
        int notRob = max(l[0], l[1]) + max(r[0], r[1]);
        return {notRob, doRob};
    }
};