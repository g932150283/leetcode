/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode* f = head;
        ListNode* s = head;
        while(k-- > 0){
            f = f->next;
        }
        while(f){
            f = f->next;
            s = s->next;
        }
        return s->val; 
    }
};
