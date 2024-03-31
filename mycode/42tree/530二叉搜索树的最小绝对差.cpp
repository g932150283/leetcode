#include <bits/stdc++.h>
#include <cstdlib>

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
    int res = INT_MAX;
    TreeNode* pre = nullptr;

    void backtracking(TreeNode* root){
        if(root == nullptr){
            return;
        }
        backtracking(root->left);
        if(pre != nullptr){
            res = min(res, abs(pre->val - root->val));
        }
        pre = root;
        backtracking(root->right);
    }
public:
    
    int getMinimumDifference(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        backtracking(root);
        return res;


    }
};


int main(){

    TreeNode* m1 = new TreeNode(4);
    TreeNode* m2 = new TreeNode(2);
    TreeNode* m3 = new TreeNode(6);
    TreeNode* m4 = new TreeNode(1);
    TreeNode* m5 = new TreeNode(3);
    m1->left = m2;
    m1->right = m3;
    m2->left = m4;
    m2->right = m5;
    Solution* s = new Solution();

    s->getMinimumDifference(m1);

}