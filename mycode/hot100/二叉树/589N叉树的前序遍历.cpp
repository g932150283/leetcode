#include <bits/stdc++.h>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Node{
public:
    int val;
    vector<Node*> children;
    
    Node(){}

    Node(int _val) : val(_val){

    }

    Node(int _val, vector<Node*> _children) : val(_val), children(_children) {

    } 


};
class Solution {
    vector<int> res;
    void traversal(Node* root){
        if(root == nullptr){
            return;
        }
        res.push_back(root->val);
        for(auto r : root->children){
            traversal(r);
        }
    }
public:
    vector<int> preorder(Node* root) {
        traversal(root);
        return res;
    }
};