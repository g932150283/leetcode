#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int sum = 0;
    int reversePairs(vector<int>& record) {
        mergeSort(record, 0, record.size() - 1);
        return sum;
    }

    void merge(vector<int> &nums, int left, int mid, int right){
        vector<int> tmp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right){
            if(nums[i] <= nums[j]){
                tmp[k++] = nums[i++];
            }else{
                sum = sum + mid + 1 - i;
                tmp[k++] = nums[j++];
            }
        }
        
        while (i <= mid){
            tmp[k++] = nums[i++];
        }

        while (j <= right){
            tmp[k++] = nums[j++];
        }
        
        for(k = 0; k < tmp.size(); k++){
            nums[left + k] = tmp[k];
        }
    }

    void mergeSort(vector<int> &nums, int left, int right){
        if(left >= right){
            return;
        }

        int mid = (left + right) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
};


int main(){

    Solution* s = new Solution();
    vector<int> v = {7, 3, 2, 6, 0, 1, 5, 4};
    s->mergeSort(v, 0, v.size() - 1);

    return 0;
}
