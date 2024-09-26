#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.

 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
    // 后序遍历
    // ListNode* left;
    // bool traverse(ListNode* right){
    //     if(right == nullptr){
    //         return true;
    //     }
    //     bool res = traverse(right->next);
    //     res = res && (left->val == right->val);
    //     left = left->next;
    //     return res;
    // }
    
    // 反转
    ListNode* reverse(ListNode* head){
        ListNode *pre, *nxt, *cur;
        cur = nxt = head;
        pre = nullptr;
        while (cur)
        {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
            /* code */
        }
        return pre;
        
        

    }
    // 找中点
    ListNode* getMid(ListNode* head){
        ListNode *s, *f;
        s = f = head;
        while (f->next != nullptr && f != nullptr)
        {
            f = f->next;
            s = s->next;
            /* code */
        }
        if(f){
            s = s->next;
        }
        return s;
        
    }

public:

    bool isPalindrome(ListNode* head) {
        // left = head;
        // return traverse(left);
        ListNode* l = head;
        ListNode* r = reverse(getMid(head));
        while (l && r)
        {
            if(l->val != r->val){
                return false;
            }
            l = l->next;
            r = r->next;
            /* code */
        }
        return true;
        
        
    }


};

int main(){

    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(2);
    ListNode* l4 = new ListNode(1);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;

    Solution* s = new Solution();
    s->isPalindrome(l1);

    return 0;
}