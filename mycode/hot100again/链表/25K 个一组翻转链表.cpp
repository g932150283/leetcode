

class Solution {
    ListNode* reverse(ListNode* a, ListNode* b){
        ListNode *pre, *cur, *nxt;
        pre = nullptr;
        cur = a;
        nxt = a;
        while (cur != b)
        {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
            /* code */
        }
        return pre;
        
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *a, *b;
        a = b = head;
        for(int i = 0; i < k; i++){
            if(b == nullptr){
                return head;
            }
            b = b->next;
        }
        ListNode* newHead = reverse(a, b);
        a->next = reverseKGroup(b, k);
        return newHead;
    }
};