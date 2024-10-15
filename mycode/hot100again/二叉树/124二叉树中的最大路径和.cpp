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