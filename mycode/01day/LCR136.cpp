/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<bits/stdc++.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val == val){
            return head->next;
        }
        
        ListNode* p = head;
        while (p->next != nullptr && p->next->val != val){
            p = p->next;
        }

        if(p->next != nullptr){
            p->next = p->next->next;
        }

        return head;
        

        
    }
};

int main(){



    return 0;
}