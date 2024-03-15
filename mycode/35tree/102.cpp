
#include<bits/stdc++.h>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r){}
    /* data */
};


class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        queue<TreeNode*> q1;
        if(root == nullptr){
            return res;
        }
        q.emplace(root);
        while (!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q1.emplace(node->left);
                }
                if(node->right){
                    q1.emplace(node->right);
                }
                path.push_back(node->val);
            }
            res.push_back(path);
            path.clear();
        }
        return res;
        
    }
};