/**
 * Definition for singly-linked list.

 */

#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode();
        ListNode* big = new ListNode();
        ListNode *s = small, *b = big;
        ListNode* cur = head;
        while (cur)
        {
            if(cur->val < x){
                s->next = cur;
                s = s->next;
            }else{
                b->next = cur;
                b = b->next;
            }
            // cur = cur->next;
            ListNode* tmp = cur->next;
            cur->next = nullptr;
            cur = tmp;
            /* code */
        }
        s->next = big->next;
        return small->next;
        
    }
};


int main(){

    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(4);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(2);
    ListNode* l5 = new ListNode(5);
    ListNode* l6 = new ListNode(2);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;

    Solution* s = new Solution();
    s->partition(l1, 3);

    return 0;
}