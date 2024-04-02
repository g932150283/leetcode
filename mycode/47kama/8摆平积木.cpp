#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while (cin >> n)
    {
        if(n == 0){
            break;
        }
        int ji[n];
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> ji[i];
            sum += ji[i];
        }
        int res = 0;
        int ave = sum / n;
        for(int i = 0; i < n; i++){
            if(ji[i] > ave){
                res += (ji[i] - ave);
            }
        }
        cout << res << endl;
        cout << endl;

        /* code */
    }
    

    return 0;
}