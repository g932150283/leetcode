#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    while (cin >> n)
    {
        int sum = 0;
        while (n)
        {
            if(n % 10 % 2 == 0){
                sum += n % 10;
            }
            n = n / 10;
            /* code */
        }
        cout << sum << endl;
        cout << endl;
        
    }
    


    return 0;
}