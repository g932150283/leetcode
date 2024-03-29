#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() == 0){
            return 0;
        }
        int sum = 0;
        vector<int> suger(ratings.size(), 1);
        for(int i = 0; i < ratings.size() - 1; i++){
            if(ratings[i] > ratings[i + 1]){
                while(suger[i] <= suger[i + 1]){
                    suger[i]++;
                }
                
            }else if(ratings[i] < ratings[i + 1]){
                while(suger[i + 1] <= suger[i]){
                    suger[i + 1]++;
                }
                

            }
        }
        for(int i = ratings.size() - 1; i >= 1; i--){
            if(ratings[i] > ratings[i - 1]){
                while(suger[i] <= suger[i - 1]){
                    suger[i]++;
                }
            }else if(ratings[i] < ratings[i - 1]){
                while(suger[i - 1] <= suger[i]){
                    suger[i - 1]++;
                }
            }
        }

        for(auto s : suger){
            sum += s;
        }
        return sum;
        
    }
};


int main(){

    vector<int> v = {1,3,4,5,2};
    Solution* s = new Solution();
    s->candy(v);
}