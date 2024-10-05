class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                while (slow != head)
                {
                    head = head->next;
                    slow = slow->next;
                    /* code */
                }
                return slow;
                
            }
            /* code */
        }
        return nullptr;
    }
};