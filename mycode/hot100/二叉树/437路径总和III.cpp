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
    void dfs(TreeNode* root, int sum, int cur_sum){
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


int main(){

    TreeNode* t1 = new TreeNode(10);
    TreeNode* t2 = new TreeNode(2);
    TreeNode* t3 = new TreeNode(-3);
    TreeNode* t4 = new TreeNode(3);
    TreeNode* t5 = new TreeNode(2);
    TreeNode* t6 = new TreeNode(11);
    TreeNode* t7 = new TreeNode(3);
    TreeNode* t8 = new TreeNode(-2);
    TreeNode* t9 = new TreeNode(1);
    
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;
    t3->right = t6;
    t4->left = t7;
    t4->right = t8;
    t5->right = t9;

    Solution* s = new Solution();
    s->pathSum(t1, 8);

    return 0;
}