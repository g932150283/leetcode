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
    TreeNode* construct(vector<int>& nums, int l, int r){
        if(l > r){
            return nullptr;
        }
        int m_val = -1;
        int index = -1;
        for(int i = l; i <= r; i++){
            if(m_val < nums[i]){
                m_val = nums[i];
                index = i;
            }
        }
        TreeNode* root = new TreeNode(m_val);
        root->left = construct(nums, l, index - 1);
        root->right = construct(nums, index + 1, r);
        return root;

    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0){
            return nullptr;
        }
        return construct(nums, 0, nums.size() - 1);
    }
};