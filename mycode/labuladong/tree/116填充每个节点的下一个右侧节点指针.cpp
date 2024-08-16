#include<bits/stdc++.h>

using namespace std;

/*
// Definition for a Node.

*/
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr){
            return nullptr;
        }
        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            Node* cur = nullptr;
            for(int i = 0; i < n - 1; i++){
                cur = q.front();
                q.pop();
                cur->next = q.front();
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
            cur = q.front();
            q.pop();
            cur->next = nullptr;
            if(cur->left){
                q.push(cur->left);
            }
            if(cur->right){
                q.push(cur->right);
            }
            /* code */
        }
        return root;
    }
    
};