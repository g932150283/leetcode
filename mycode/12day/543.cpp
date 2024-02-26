/**
 * Definition for a binary tree node.

 */

#include <bits/stdc++.h>
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
public:
    int MAX = 0;
    int dfs(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int L = dfs(root->left);
        int R = dfs(root->right);
        if(L + R > MAX){
            MAX = L + R;
        }
        return max(L, R) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return MAX;
    }
};

TreeNode* vectorToTree(vector<int> list){
    TreeNode* root = new TreeNode(list[0]);
    queue<TreeNode *> q;
    q.emplace(root);
    int i = 1;
    while (!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        if(list[i] != INT_MAX){
            node->left = new TreeNode(list[i]);
            q.emplace(node->left);
        }
        i++;
        if(list[i] != INT_MAX){
            node->right = new TreeNode(list[i]);
            q.emplace(node->right);
        }
        i++;
    }
    return root;
}


int main(){

    vector<int> v = {1, 2, INT_MAX, 4, 5, 6, INT_MAX, INT_MAX, 3, INT_MAX, INT_MAX, INT_MAX, INT_MAX};
    TreeNode* root = vectorToTree(v);
    Solution* s = new Solution();
    cout << s->diameterOfBinaryTree(root) << endl;
    return 0;
}