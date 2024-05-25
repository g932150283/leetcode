/**
 * Definition for singly-linked list.

 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr){
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* end = dummy;
        ListNode* mPre = dummy;
        ListNode* cur = head;
        
        int num = 0;
        while (1)
        {
            end = end->next;
            num++;
            if(end == nullptr) break;
            if(num % k == 0){
                ListNode* pre = end->next;
                for(int i = 0; i < k; i++){
                    ListNode* tmp = cur->next;
                    cur->next = pre;
                    pre = cur;
                    cur = tmp;
                }
                ListNode* nxt = mPre->next;
                mPre->next->next = cur;
                mPre->next = pre;
                mPre = nxt;

                cur = mPre->next;
                end = mPre; 
            }
            /* code */
        }
        return dummy->next;
    }
};


int main(){

    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;

    Solution* s = new Solution();
    s->reverseKGroup(l1, 2);



    return 0;
}