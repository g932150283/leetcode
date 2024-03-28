#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> money(3);
        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5){
                money[0]++;
            }else if(bills[i] == 10){
                if(money[0] > 0){
                    money[0]--;
                    money[1]++;
                }else{
                    return false;
                }
            }else{
                // 10 + 5
                if(money[0] > 0 && money[1] > 0){
                    money[0]--;
                    money[1]--;
                }else if(money[0] > 2){
                    money[0]= money[0] - 3;     
                }else{
                    return false;
                }
            }

        }
        return true;
    }
};