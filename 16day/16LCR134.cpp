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
            if (y % 2 == 1) {
                res = res * x;
            }
            x = x * x;
            y = y / 2;
        }
        return res;
    }
};

int main(){

    cout << Solution().myPow(2,2) << endl;
    return 0;
}
