#include<bits/stdc++.h>

using namespace std;
struct ListNode1
{
    int val;
    ListNode1* next;
    ListNode1(int x) : val(x), next(nullptr) {};
    /* data */
};

class Solution {
    void reverse(vector<int>& nums, int left, int right){
        while (left < right)
        {
            swap(nums[left], nums[right]);
            left++;
            right--;
            /* code */
        }
        
    }
public:
    void rotate(vector<int>& nums, int k) {
        // vector<int> temp;
        // int len = nums.size();
        // ListNode1* head = new ListNode1(nums[0]);
        // ListNode1* cur = head;
        // for(int i = 1; i < nums.size(); i++){
        //     cur->next = new ListNode1(nums[i]);
        //     cur=cur->next;
        // }
        // cur->next = head;
        // for(int i = 0; i < len - k % len; i++){
        //     head = head->next;
        // }
        // for(int i = 0; i < len; i++){
        //     nums[i] = head->val;
        //     head=head->next;
        // }
        k = k % nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
        
    }
};

int main(){

    Solution* s = new Solution();
    vector<int> v = {-1,-100,3,99};
    s->rotate(v, 2);

    return 0;
}