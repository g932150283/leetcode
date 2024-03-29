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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0){
            return nullptr;
        }
        int maxNum = INT_MIN;
        int maxIndex = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > maxNum){
                maxIndex = i;
                maxNum = nums[i];
            }
        }
        TreeNode* root = new TreeNode(maxNum);
        vector<int> left(nums.begin(), nums.begin() + maxIndex);
        vector<int> right(nums.begin() + maxIndex + 1, nums.end());
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;

    }
};