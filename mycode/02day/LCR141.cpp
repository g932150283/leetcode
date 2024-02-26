#include<bits/stdc++.h>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {
    }
};

class Solution {
public:
    ListNode* trainningPlan(ListNode* head) {
        // if(head == nullptr || head->next == nullptr){
        //     return head;
        // }
        // ListNode* cur = head;
        // ListNode* pre = nullptr;
        // while (cur){
        //     ListNode* temp = cur->next;
        //     cur->next = pre;
        //     pre = cur;
        //     cur = temp;
        // }

        // return pre;

        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* temp = trainningPlan(head->next);
        head->next->next = head;
        head->next = nullptr;
        return temp;
        

    }
};


ListNode *vectorToLinkedList(vector<int> list) {
    ListNode *dum = new ListNode(0);
    ListNode *head = dum;
    for (int val : list) {
        head->next = new ListNode(val);
        head = head->next;
    }
    return dum->next;
}

void show(ListNode* head){
    while (head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    
}


int getLength(ListNode* head){
    int count = 0;
    while (head != nullptr)
    {
        count++;
        head = head->next;
        /* code */
    }
    return count; 

}


ListNode *add(ListNode* head1, ListNode* head2) {
    // 1 -> 2 -> 3 -> 4
    //           3 -> 4
    // 1 -> 2 -> 6 -> 8
    // 先反转，再相加，再反转
    Solution *slt = new Solution();
    // 先反转
    ListNode* l1 = slt->trainningPlan(head1);
    ListNode* l2 = slt->trainningPlan(head2);
    // show(l1);
    // cout << "length l1 = " << getLength(l1) << endl;
    // show(l2);
    // cout << "length l2 = " << getLength(l2) << endl;
    ListNode* cur;
    ListNode* another;
    if(getLength(l1) > getLength(l2)){
        cur = l1;
        another = l2;
    }else{
        cur = l2;
        another = l1;
    }
    ListNode* pre = cur;
    while (another != nullptr)
    {
        cur->val += another->val;
        another = another->next;
        cur = cur->next;
        /* code */
    }
    cur = pre;
    while (cur != nullptr){
        if(cur->val >= 10 && cur->next != nullptr){
            cur->val -= 10;
            cur->next->val += 1;
        }else if(cur->val >= 10 && cur->next == nullptr){
            ListNode *l = new ListNode(1);
            cur->val -= 10;
            cur->next = l;
            cur = l;
        }
        cur = cur->next;
    }

    return slt->trainningPlan(pre);; 


}

int main(){
    ListNode* l1 = vectorToLinkedList(vector<int>{4, 5, 1, 9});
    ListNode* l2 = vectorToLinkedList(vector<int>{6, 1, 1, 9});
    // Solution *slt = new Solution();
    // ListNode* l1 = slt->trainningPlan(l1);
    // show(l1);
    ListNode* l = add(l1, l2);
    show(l);
    return 0;
}