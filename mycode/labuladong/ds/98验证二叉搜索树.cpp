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
    bool isValid(TreeNode* root, TreeNode* min, TreeNode* max){
        if(root == nullptr){
            return true;
        }
        if(min != nullptr && root->val <= min->val){
            return false;
        }
        if(max != nullptr && root->val >= max->val){
            return false;
        }
        return isValid(root->left, min, root) && isValid(root->right, root, max);
    }
public:
    bool isValidBST(TreeNode* root) {   
        return isValid(root, nullptr, nullptr);
    }
};