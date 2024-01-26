#include "../include/include.hpp"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* r = new ListNode(0);
        ListNode* s = r;
        while (p != nullptr && q != nullptr){
            if(p->val < q->val){
                s->next = p;
                p = p->next;
            }else{
                s->next = q;
                q = q->next;
            }
            s = s->next;
        }

        if(q != nullptr){
            s->next = q;
        }

        if(p != nullptr){
            s->next = p;
        }

        return r->next;
        
    }
};


int main(){
    // ======= Test Case =======
    ListNode *l1 = vectorToLinkedList(vector<int>{1, 2, 4});
    ListNode *l2 = vectorToLinkedList(vector<int>{1, 3, 4});
    // ====== Driver Code ======
    Solution *slt = new Solution();
    ListNode *res = slt->mergeTwoLists(l1, l2);
    PrintUtil::printLinkedList(res);


    return 0;
}