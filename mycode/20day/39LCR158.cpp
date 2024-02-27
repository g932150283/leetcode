#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int inventoryManagement(vector<int>& stock) {
        if(stock.size() == 0){
            return 0;
        }
        int res = stock[0];
        int time = 1;
        for(int i = 1; i < stock.size(); i++){
            if(time == 0){
                res = stock[i];
                time++;
            }else if(res == stock[i]){
                time++;
            }else{
                time--;
            }
        }
        return res;
    }

};

int main(){

    vector<int> v = {2,2,1,1,1,2,2};
    Solution* s = new Solution();
    cout << s->inventoryManagement(v);
    return 0;
}