#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    /* data */
};


TreeNode* getNode(vector<TreeNode*> v, int val){
    TreeNode* res = nullptr;
    for(auto a : v){
        if(a->val == val){
            res = a;
        }
    }
    return res;
}

int main() {
    int n;
    while(cin >> n){
        vector<TreeNode*> v;
        for(int i = 0; i < n; i++){
            v.push_back(new TreeNode(i + 1));
        }
        for(int i = 0; i < n; i++){
            int a, b;
            cin >> a >> b;
            TreeNode* node = v[i];
            if(a > 0){
                TreeNode* tmp = getNode(v, a);
                if(tmp){
                    node->left = tmp;
                }                
            }else{
                node->left = nullptr;
            }

            if(b > 0){
                TreeNode* tmp = getNode(v, b);
                if(tmp){
                    node->right = tmp;
                }                
            }else{
                node->right = nullptr;
            }

        }
        
        cout << 1 << endl;
    }
}
// 64 位输出请用 printf("%lld")