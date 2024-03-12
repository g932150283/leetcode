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
    int res = 0;
    int minCameraCover(TreeNode* root) {
        if(dfs(root) == 0){
            res++;
        }
        return res;
    }
    
    int dfs(TreeNode* root){
        if(root == nullptr){
            return 2;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        // 左右节点都有覆盖
        if(left == 2 && right == 2){
            return 0;
        }
        // 有摄像头
        if(left == 0 || right == 0){
            res++;
            return 1;
        }

        // 被覆盖
        if(left == 1 || right == 1){
            return 2;
        }

        return -1;
    }
};