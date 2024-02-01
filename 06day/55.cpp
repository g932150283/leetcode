#include<bits/stdc++.h>

using namespace std;


/**
 * Definition for a binary tree node.
 * 
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
    int calculateDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int left = calculateDepth(root->left);
        int right = calculateDepth(root->right);

        return max(left, right) + 1;
    }
};


TreeNode *vectorToTree(vector<int> list) {
    TreeNode *root = new TreeNode(list[0]);
    queue<TreeNode *> que;
    que.emplace(root);
    int i = 1;
    while (!que.empty()) {
        TreeNode *node = que.front();
        que.pop();
        if (list[i] != INT_MAX) {
            node->left = new TreeNode(list[i]);
            que.emplace(node->left);
        }
        i++;
        if (list[i] != INT_MAX) {
            node->right = new TreeNode(list[i]);
            que.emplace(node->right);
        }
        i++;
    }
    return root;
}

int main(){

    TreeNode *root = vectorToTree(vector<int>{3, 9, 20, INT_MAX, INT_MAX, 15, 7, INT_MAX, INT_MAX, INT_MAX, INT_MAX});
    // ====== Driver Code ======
    Solution *slt = new Solution();
    int res = slt->calculateDepth(root);
    cout << res << endl;

    return 0;
}