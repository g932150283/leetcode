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