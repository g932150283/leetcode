/**
 * Definition for a binary tree node.

 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
        {
            return "";
        }
        // 层序遍历
        queue<TreeNode *> q;
        q.emplace(root);
        ostringstream output;
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node == nullptr)
            {
                output << "null" << " ";
                continue;
            }
            else
            {
                output << node->val << " ";
            }
            q.emplace(node->left);
            q.emplace(node->right);
        }
        // output.str() 将 ostringstream 对象中的数据转换为 string 类型，以便将其作为函数的返回值返回。
        return output.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty()) return nullptr;
        vector<string> s = split(data);
        TreeNode* root = new TreeNode(stoi(s[0]));
        queue<TreeNode *> q;
        q.emplace(root);
        int i = 1;
        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(s[i] != "null"){
                node->left = new TreeNode(stoi(s[i]));
                q.emplace(node->left);
            }
            i++;
            if(s[i] != "null"){
                node->right = new TreeNode(stoi(s[i]));
                q.emplace(node->right);
            }
            i++;
        }
        
        return nullptr;
    }

    vector<string> split(string& s){
        vector<string> res;
        int n = s.size();
        int i = 0;
        while (i < n)
        {
            int j = i + 1;
            while (j < n && s[j] != ' ')
            {
                j++;
            }
            res.push_back(s.substr(i, j-i));
            i = j + 1;            
        }
        return res;
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
    Codec* s = new Codec();
    cout << s->serialize(root) << endl;
    string st = "6 2 8 0 4 7 9 null null 3 5 null null null null null null null null";
    s->deserialize(st);
    return 0;
}