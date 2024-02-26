/**
 * Definition for a binary tree node.

 */
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val){
            swap(p, q);
        }
        while (root != nullptr){
            if(root->val < p->val){
                root = root->right;
            }
            else if (root->val > q->val){
                root = root->left;
            }else{
                break;
            }
        }
        return root;
        
    }
};

TreeNode* vectorToTree(vector<int> list){
    TreeNode *root = new TreeNode(list[0]);
    queue<TreeNode *> q;
    q.emplace(root);
    int i = 1;
    while (!q.empty()){
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
    vector<int> v = {6,2,8,0,4,7,9,INT_MAX,INT_MAX,3,5,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX};
    TreeNode* root = vectorToTree(v);
    TreeNode* p = new TreeNode(4);
    TreeNode* q = new TreeNode(2);
    Solution* s = new Solution();
    cout << s->lowestCommonAncestor(root, p, q)->val << endl;
    return 0;
}