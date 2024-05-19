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
    vector<TreeNode*> res;
    void preorder(TreeNode* root){
        if(root == nullptr){
            return;
        }
        res.push_back(root);
        preorder(root->left);
        preorder(root->right);
    }
public:
    void flatten(TreeNode* root) {
        // if(root == nullptr){
        //     return;
        // }
        // preorder(root);
        // TreeNode* cur = root;
        // for(int i = 1; i < res.size(); i++){
        //     cur->left = nullptr;
        //     cur->right = res[i];
        //     cur = cur->right;
        // }
        TreeNode* cur = root;
        while (cur != nullptr)
        {
            /* code */
            if(cur->left != nullptr){
                TreeNode* tmp = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
                TreeNode* cur1 = cur->right;
                while (cur1->right)
                {
                    cur1 = cur1->right;
                    /* code */
                }
                cur1->right = tmp;
            }
            cur = cur->right;
        }
        
        
        
        
            
    }
};

int main(){

    TreeNode* t1 = new TreeNode(1);
    TreeNode* t2 = new TreeNode(2);
    TreeNode* t3 = new TreeNode(3);
    TreeNode* t4 = new TreeNode(4);
    TreeNode* t5 = new TreeNode(5);
    TreeNode* t6 = new TreeNode(6);
    Solution* s = new Solution();
    t1->left = t2;
    t1->right = t5;
    t2->left = t3;
    t2->right = t4;
    t5->right = t6;
    // t1->left = t2;
    // t2->left = t3;
    s->flatten(t1);

    return 0;
}