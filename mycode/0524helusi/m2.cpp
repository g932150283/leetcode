/*
判断一棵树是不是镜像二叉树
*/

#include<bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
    /* data */
};

bool getAns(TreeNode* l, TreeNode* r){
    if(l == nullptr && r == nullptr){
        return true;
    }else if(l == nullptr && r != nullptr){
        return false;
    }else if(l != nullptr && r == nullptr){
        return false;
    }else if(l->val != r->val){
        return false;
    }
    return getAns(l->left, r->right) && getAns(l->right, r->left);
}


int main(){
    TreeNode* t1 = new TreeNode(1);
    TreeNode* t2 = new TreeNode(2);
    TreeNode* t3 = new TreeNode(2);
    TreeNode* t4 = new TreeNode(4);
    TreeNode* t5 = new TreeNode(4);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t3->right = t5;

    TreeNode* t11 = new TreeNode(1);
    TreeNode* t22 = new TreeNode(2);
    TreeNode* t33 = new TreeNode(2);
    t11->left = t22;
    t22->right = t33;

    cout << getAns(t1->left, t1->right) << endl;
    cout << getAns(t11->left, t11->right) << endl;
}