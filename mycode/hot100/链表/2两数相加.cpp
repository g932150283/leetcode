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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* cur = res;
        int flag = 0;
        while (l1 && l2)
        {
            res->next = new ListNode(l1->val + l2->val);
            res = res->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            
            res->next = new ListNode(l1->val);
            res = res->next;
            l1 = l1->next;
        }
        while (l2)
        {
            res->next = new ListNode(l2->val);
            res = res->next;
            l2 = l2->next;
        }
        ListNode* pre = cur->next;
        while (pre)
        {
            if(pre->val > 9){
                if(pre->next){
                    pre->val = pre->val - 10;
                    pre->next->val = pre->next->val + 1;
                }else{
                    pre->val = pre->val - 10;
                    pre->next = new ListNode(1);
                }
            }
            pre = pre->next;
            /* code */
        }
        
        return cur->next;
        
        
    }
};


int main(){

    ListNode* l1 = new ListNode();
    ListNode* cur1 = l1;

    ListNode* l2 = new ListNode();
    ListNode* cur2 = l2;
    int i = 0;
    while (i < 7)
    {
        cur1->next = new ListNode(9);
        cur1 = cur1->next;
        i++;
    }
    i = 0;
    while (i < 4)
    {
        cur2->next = new ListNode(9);
        cur2 = cur2->next;
        i++;
    }
    
    Solution* s = new Solution();
    s->addTwoNumbers(l1->next, l2->next);

    return 0;
}