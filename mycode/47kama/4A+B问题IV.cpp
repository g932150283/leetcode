#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, a;
    while (cin >> n)
    {
        if(n == 0){
            break;
        }
        int sum = 0;
        while (n--)
        {
            cin >> a;
            sum += a;
            /* code */
        }
        cout << sum << endl;
        
        
    }
    
    
    
    

    return 0;
}