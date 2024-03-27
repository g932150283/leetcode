#include<bits/stdc++.h>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    /* data */
};

class Solution {
    vector<vector<int>> res;
    vector<int> path;
    int depth;
    void backtracking(TreeNode* root){
        //结束条件？
        path.push_back(root->val);

        if(path.size() == depth){
            res.push_back(path);
            return;
        }

        if(root->left){
            backtracking(root->left);
            path.pop_back();
        }

        if(root->right){
            backtracking(root->right);
            path.pop_back();
        }



    }
    int getDepth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        return 1 + max(left, right);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        depth = getDepth(root);
        backtracking(root);
        return res.front().back();
        
    }
};


int main(){

    TreeNode* n1 = new TreeNode(2);
    TreeNode* n2 = new TreeNode(1);
    TreeNode* n3 = new TreeNode(3);
    n1->left = n2;
    n1->right = n3;

}