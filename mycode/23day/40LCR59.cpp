#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> inventoryManagement(vector<int>& stock, int cnt) {
        quickSort(stock, 0, stock.size() - 1);
        vector<int> res;
        int num = 0;
        for(int s : stock){
            if(num == cnt){
                break;
            }
            num++;
            res.push_back(s);
        }
        return res;
    }

    void quickSort(vector<int> &nums, int left, int right){
        if(left >= right){
            return;
        }
        int pivot = partition(nums, left, right);
        quickSort(nums, left, pivot - 1);
        quickSort(nums, pivot + 1, right);
    }

    int partition(vector<int> &nums, int left, int right){
        int l = left, r = right;
        while (l < r){
            while ((l < r) && nums[left] <= nums[r]){
                r--;
            }
            while ((l < r) && nums[left] >= nums[l]){
                l++;
            }
            swap(nums[l], nums[r]);
        }
        // 将基准数交换至两子数组的分界线
        swap(nums[l], nums[left]);
        // 返回基准数的索引
        return l;
    }
};

int main(){

    vector<int> v = {0, 3, 30, 34, 5, 9};
    Solution* s = new Solution();
    s->inventoryManagement(v, 3);
    return 0;
}