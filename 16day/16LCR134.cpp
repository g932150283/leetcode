#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        long y = n;
        if (n < 0) {
            y = -y;
            x = 1 / x;
        }
        while (y > 0) {
            // 看低位
            if ((y & 1) == 1) {
                res = res * x;
            }
            x = x * x;
            y = y >> 1;
        }
        return res;
    }
};




double power(double base,  int exponent){
    if(base == 0){
        return 0;
    }
    if(exponent == 1){
        return base;
    }

    int y = exponent;
    double res = 1;
    if(y < 0){
        y = -y;
        base = 1 / base;
    }

    while (y > 0)
    {
        if(y & 1 == 1){
            res = res * base;
        }
        base = base * base;
        y = y >> 1;
        /* code */
    }
    return res;
    
}

int main(){

    cout << Solution().myPow(3,5) << endl;
    cout << power(2, -2) << endl;
    return 0;
}
