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


int main(){
    ListNode* l = vectorToLinkedList(vector<int>{4, 5, 1, 9});
    Solution *slt = new Solution();
    ListNode* l1 = slt->trainningPlan(l);
    show(l1);
    return 0;
}