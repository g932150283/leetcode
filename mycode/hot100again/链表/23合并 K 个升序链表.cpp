class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode* a, const ListNode* b){
            return a->val > b->val;
        };
    
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for(auto head : lists){
            if(head){
                pq.push(head);
            }
        }
        ListNode dummy(0);
        auto cur = &dummy;
        while (!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            if(node->next){
                pq.push(node->next);
            }
            cur->next = node;
            cur = cur->next;
            /* code */
        }
        return dummy.next;
        
    
    }
};