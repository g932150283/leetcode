
#include<bits/stdc++.h>

using namespace std;


/**
 * Definition for singly-linked list.

 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // if(head == nullptr || head->next == nullptr){
        //     return head;
        // }
        // ListNode* re = reverseList(head->next);
        // head->next->next = head;
        // head->next = nullptr;
        // return re;
        // ListNode *cur, *nxt, *pre;
        // cur = head;
        // nxt = head;
        // pre = nullptr;
        // while (cur)
        // {
        //     nxt = cur->next;
        //     cur->next = pre;
        //     pre = cur;
        //     cur = nxt;
        //     /* code */
        // }
        // return pre;
        // ListNode *pre, *cur, *nxt;
        // cur = nxt = head;
        // pre = nullptr;
        // while (cur)
        // {
        //     nxt = cur->next;
        //     cur->next = pre;
        //     pre = cur;
        //     cur = nxt;
        //     /* code */

        // }
        // return pre;
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* re = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return re;
        
        
    }
};