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
        if(root == nullptr){
            return res;
        }
        stack<TreeNode*> s;
        s.emplace(root);
        while (!s.empty())
        {
            TreeNode* node = s.top();
            s.pop();
            res.push_back(node->val);
            if(node->right){
                s.emplace(node->right);
            }
            if(node->left){
                s.emplace(node->left);
            }
            /* code */
        }
        
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
