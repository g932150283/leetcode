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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr){
            return res;
        }
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while (cur != nullptr || !s.empty())
        {
            if(cur != nullptr){
                s.push(cur);
                cur = cur->left;           // 左
            }else{
                cur = s.top();
                s.pop();
                res.push_back(cur->val);   // 中
                cur = cur->right;          // 右
            }
            
            /* code */
        }
        
        return res;
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
            node->right = new TreeNode(v[i]);
            q.emplace(node->right);
        }
        i++;
        
        /* code */
    }
    return root;
    


}


int main(){
    vector<int> v = {1,INT_MAX,2,3,INT_MAX,INT_MAX,INT_MAX};
    TreeNode* root = vectorToTree(v);
    Solution* s = new Solution();
    s->inorderTraversal(root);
    return 0;
}