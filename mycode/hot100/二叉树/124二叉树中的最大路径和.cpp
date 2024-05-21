#include<bits/stdc++.h>

using namespace std;

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
    int dfs(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        res = max(res, left + right + root->val);
        return max(max(left, right) + root->val, 0);
    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};