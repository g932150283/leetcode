class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }
        Node* cur = head;
        while (cur)
        {
            Node* node = new Node(cur->val);
            node->next = cur->next;
            cur->next = node;
            cur = cur->next->next;
            /* code */
        }

        cur = head;
        while (cur)
        {
            Node* pre = cur->next;
            if(cur->random != nullptr){
                pre->random = cur->random->next;
            }else{
                pre->random = nullptr;
            }
            /* code */
            cur = cur->next->next; 
        }

        cur = head->next;
        Node* pre = head, *res = head->next;
        while (cur->next)
        {
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre = pre->next;
            cur = cur->next;
            // cur
            /* code */
        }
        pre->next = nullptr;
        return res;
        
        
    }
};