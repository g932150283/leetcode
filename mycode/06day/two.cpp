#include<bits/stdc++.h>

using namespace std;

int main(){

    for(int i = 1; i < 17; i++){
        if(!(i & (i - 1))){
            cout << i << " is two" << endl;
        }
    }

    return 0;
}