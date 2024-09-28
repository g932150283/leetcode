
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        while (a != b)
        {
            if(a != nullptr){
                a = a->next;
            }else{
                a = headB;
            }
            if(b != nullptr){
                b = b->next;
            }else{
                b = headA;
            }
            /* code */
        }
        return a;
        
    }
};