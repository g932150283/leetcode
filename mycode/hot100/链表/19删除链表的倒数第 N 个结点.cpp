#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
    /* data */
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // if(head == nullptr){
        //     return head;
        // }
        // ListNode* dummy = new ListNode(0);
        // dummy->next = head;
        // ListNode* cur = head;
        // ListNode* fast = head;
        // head = dummy;
        // while (n > 0)
        // {
        //     fast = fast->next;
        //     n--;
        //     /* code */
        // }

        // while (fast != nullptr)
        // {
        //     dummy = dummy->next;
        //     fast = fast->next;
        //     cur = cur->next;
        //     /* code */
        // }
        // dummy->next = cur->next;
        // return head->next;
        

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *r, *l;
        r = dummy;
        l = dummy;
        while (n--)
        {
            r = r->next;
            /* code */
        }
        while (r->next)
        {
            r = r->next;
            l = l->next;
            /* code */
        }
        ListNode* node = l->next;
        l->next = l->next->next;
        delete node;
        return dummy->next;
        
        
        

    }
};