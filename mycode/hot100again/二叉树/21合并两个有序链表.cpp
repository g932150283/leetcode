#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.

 */

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // ListNode* node = new ListNode();
        // ListNode* cur = node;
        // while (list1 && list2)
        // {
        //     if(list1->val < list2->val){
        //         cur->next = new ListNode(list1->val);
        //         list1 = list1->next;
        //         cur = cur->next; 
        //     }else{
        //         cur->next = new ListNode(list2->val);
        //         list2 = list2->next;
        //         cur = cur->next; 
        //     }
        //     /* code */
        // }
        // while (list1)
        // {
        //     cur->next = new ListNode(list1->val);
        //     list1 = list1->next;
        //     cur = cur->next; 
        //     /* code */
        // }
        // while (list2)
        // {
        //     cur->next = new ListNode(list2->val);
        //     list2 = list2->next;
        //     cur = cur->next; 
        //     /* code */
        // }
        // return node->next;
        ListNode dummy(0);
        ListNode* cur = &dummy;
        ListNode *p1 = list1, *p2 = list2;

        while (p1 && p2)
        {
            if(p1->val < p2->val){
                cur->next = p1;
                p1 = p1->next;
            }else{
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
            /* code */
        }
        if(p1){
            cur->next = p1;
        }
        if(p2){
            cur->next = p2;
        }
        return dummy.next;
        
        
        
        

    }
};