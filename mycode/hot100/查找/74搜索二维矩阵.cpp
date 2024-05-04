
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int t = 0;
        int b = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;

        while (t <= b)
        {
            int mid = (t + b) / 2;
            if(matrix[mid][r] == target){
                return true;
            }else if(matrix[mid][r] > target){
                b = mid - 1;
            }else{
                // matrix[mid][0] < target
                t = mid + 1;
            }
            /* code */
        }
        if(t > matrix.size() - 1){
            return false;
        }
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if(matrix[t][mid] == target){
                return true;
            }else if(matrix[t][mid] > target){
                r = mid - 1;
            }else{
                // matrix[t][mid] < target
                l = mid + 1;
            }
            /* code */
        }
        return false;
        
    }
};


int main(){
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    Solution* s = new Solution();
    s->searchMatrix(matrix, 13);

    return 0;
}