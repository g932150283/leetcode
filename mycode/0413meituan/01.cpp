#include <bits/stdc++.h>
using namespace std;

bool isGood(vector<vector<int> >& nums, int i, int j) {
    if (nums[i][j] == nums[i + 1][j]
            && nums[i][j] == nums[i][j + 1]
            && nums[i][j] == nums[i + 1][j + 1]) {
        return true;
    }
    return false;
}

int main() {
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        vector<vector<int> > nums;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                cin >> nums[i][j];
            }
        }
        int res = 0;
        for (int i = 0; i < a - 1; i++) {
            for (int j = 0; j < b - 1; j++) {
                if (isGood(nums, i, j)) {
                    res++;
                }
            }
        }
        cout << res << endl;
    }
}
// 64 位输出请用 printf("%lld")