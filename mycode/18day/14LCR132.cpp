#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int cuttingBamboo(int bamboo_len) {
        if(bamboo_len <= 3){
            return bamboo_len - 1;
        }
        int b = bamboo_len % 3;
        int p = 1000000007;        
        long rem = 1;
        long x = 3;
        for(int a = bamboo_len / 3 - 1; a > 0; a = a / 2){
            if(a % 2 == 1){
                rem = (rem * x) % p;
            }
            x = (x * x) % p;
        }
        if(b == 0){
            return (int)(rem * 3 % p);
        }
        if(b == 1){
            return (int)(rem * 4 % p);
        }
        return (int)(rem * 6 % p);
    }
};

int main(){

    Solution* s = new Solution();
    cout << s->cuttingBamboo(12);
    cout << s->cuttingBamboo(13);

    return 0;
}