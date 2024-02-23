#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        uint32_t flag = 1;

        while (flag)
        {
            if(flag & n)
                count++;
            flag = flag << 1;
            /* code */
        }
        return count;
    }
};

int main(){

    Solution* s = new Solution();
    cout << s->hammingWeight(00000000000000000000000010000000) << endl;
    cout << s->hammingWeight(00000000000000000000000000001011) << endl;
    return 0;
}