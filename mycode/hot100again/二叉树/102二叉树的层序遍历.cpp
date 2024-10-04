#include <bits/stdc++.h>

using namespace std;



class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int s = q.size();
            vector<int> tmp;
            for(int i = 0; i < s; i++){
                TreeNode* node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            res.push_back(tmp);
            tmp.clear();
            /* code */
        }
        return res;
    }
};