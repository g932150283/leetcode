#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int res = 0;
        int reverse = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i - 1] < nums[i] && reverse != 1){
                res++;
                reverse = 1;
            }else if(nums[i - 1] > nums[i] && reverse != 2){
                reverse = 2;
                res++;
            }
        }
        return  res + 1;
    }
    // int wiggleMaxLength(vector<int>& nums) {
    //     int res = 1;
    //     if(nums.size() == 1){
    //         return 1;
    //     }
    //     if(nums.size() == 2 && nums[0] != nums[1]){
    //         return 2;
    //     }
    //     int left = 0;
    //     int right = 0;
    //     for(int i = 1; i <= nums.size() - 2; i++){
    //         left = nums[i] - nums[i - 1];
    //         right = nums[i + 1] - nums[i];
    //         if((left > 0 && right <= 0) || (left < 0 && right > 0)){
    //             res++;
    //         }
    //     }
    //     return ++res;
    // }
};

int main(){

    int a = 0;
    int b = 0;
    int c = a != b;
    cout << c << endl;

    return 0;
}