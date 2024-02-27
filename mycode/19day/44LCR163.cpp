#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthNumber(int k) {
        long  start = 1;
        int b = 1;
        int num = 9 * start;
        long sum = b * num;
        while (k > sum)
        {
            k = k - sum;
            start *= 10;
            b++;
            num = 9 * start;
            sum = b * num;
            /* code */
        }

        long n = start + (k - 1) / b;
        int index = (k - 1) % b;
        auto res = to_string(n)[index] - '0';
        return res;
        
    }
};

int main(){
    Solution* s = new Solution();
    cout << s->findKthNumber(1001);
}