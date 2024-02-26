#include<bits/stdc++.h>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};



class Solution {
public:
    vector<int> reverseBookList(ListNode* head) {
        
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr){
            count++;
            temp = temp->next;
        }
        vector<int> v(count);
        for(int i = count-1; i >= 0; i--){
            v[i] = head->val;
            head = head->next;
        }
        
        return v;
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

int main(){
    ListNode* l = vectorToLinkedList(vector<int>{4, 5, 1, 9});
    Solution *slt = new Solution();
    vector<int> a = slt->reverseBookList(l);
    for(auto i : a){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}