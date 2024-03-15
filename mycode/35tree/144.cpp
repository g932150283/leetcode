#include<bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
    /* data */
};


class Solution {
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        backtracking(root);
        return res;
    }
    void backtracking(TreeNode* root){
        if(root == nullptr){
            return;
        }
        //中左右
        res.push_back(root->val);
        backtracking(root->left);
        backtracking(root->right);
    }
};

TreeNode* vectorToTree(vector<int>& v){
    TreeNode* root = new TreeNode(v[0]);
    queue<TreeNode*> q;
    q.emplace(root);
    int i = 1;
    while (!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        if(v[i] != INT_MAX){
            node->left = new TreeNode(v[i]);
            q.emplace(node->left);
        }
        i++;
        if(v[i] != INT_MAX){
            node->left = new TreeNode(v[i]);
            q.emplace(node->left);
        }
        i++;
        
        /* code */
    }
    


}
