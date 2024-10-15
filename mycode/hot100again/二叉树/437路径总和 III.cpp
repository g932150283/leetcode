class Solution {
    // int count = 0;
    // void dfs(TreeNode* root, int targetSum){
    //     if(root == nullptr){
    //         return;
    //     }
    //     targetSum -= root->val;
    //     if(targetSum == 0){
    //         count++;
    //     }
        
    //     dfs(root->left, targetSum);
    //     dfs(root->right, targetSum);
    // }

    // 前缀和
    unordered_map<long long, int> prefix;
    int res = 0;
    void dfs(TreeNode* root, int sum, long long cur_sum){
        if(root == nullptr){
            return;
        }
        cur_sum += root->val;
        if(prefix.find(cur_sum - sum) != prefix.end()){
            res += prefix[cur_sum - sum];
        }
        prefix[cur_sum]++;
        dfs(root->left, sum, cur_sum);
        dfs(root->right, sum, cur_sum);
        prefix[cur_sum]--;

    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return 0;
        }
        prefix[0] = 1;
        dfs(root, targetSum, 0);
        return res;

    }
};