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
    // 1 先判断B是不是以A结点为根节点的一个子树
    //      否 判断B是否是A左右子树的一个子结点
    // 2 issubtree(a, b) b是否以a为根节点的子树
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A || !B){
            return false;
        }
        if(issubTree(A, B)){
            return true;
        }
        if(issubTree(A->left, B) || issubTree(A->right, B)){
            return true;
        }
        return false;
    }

    bool issubTree(TreeNode* A, TreeNode* B){
        if(!B){
            return true;
        }
        if(!A){
            return false;
        }
        if(A->val != B->val){
            return false;
        }

        return issubTree(A->left, B->left) && issubTree(A->right, B->right);
    }
};