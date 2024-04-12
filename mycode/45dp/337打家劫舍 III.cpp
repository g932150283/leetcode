#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x),  left(nullptr), right(nullptr){}
};




class Solution {
public:
    int rob(TreeNode* root) {
        vector<int>res = robTree(root);
        return max(res[0], res[1]);
    }

    vector<int> robTree(TreeNode* root){
        if(root == nullptr){
            return {0, 0};
        }
        vector<int> left = robTree(root->left);
        vector<int> right = robTree(root->right);
        // 0 不偷当前结点 1 偷当前结点
        int val1 = max(left[0], left[1]) + max(right[0], right[1]);
        int val2 = root->val + left[0] + right[0];
        return {val1, val2};
    }
};