class Solution
{
    int res = 0;

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        traverse(root);
        return res;
    }

    int traverse(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = traverse(root->left);
        int right = traverse(root->right);
        res = max(left + right, res);
        return max(left, right) + 1;
    }
};