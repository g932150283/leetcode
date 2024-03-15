
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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        int depth = 0;
        if(root == nullptr){
            return depth;
        }
        q.emplace(root);
        while (!q.empty())
        {
            int size = q.size();
            depth++;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.emplace(node->left);
                }
                if(node->right){
                    q.emplace(node->right);
                }
                if(!node->left && !node->right){
                    return depth;
                }
            }
        }
        return depth;
    }
};