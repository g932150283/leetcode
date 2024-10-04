class Solution {
    TreeNode* createTree(vector<int>& nums, int l, int r){
        if(l > r){
            return nullptr;
        }
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = createTree(nums, l, mid - 1);
        root->right = createTree(nums, mid + 1, r);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0){
            return nullptr;
        }
        return createTree(nums, 0, nums.size() - 1);
    }
};