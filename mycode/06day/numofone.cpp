#include<bits/stdc++.h>

using namespace std;

int main(){

    int count = 0;
    int x = 16;
    while (x){
        x = x & (x - 1);
        count++;
    }
    
    cout << "count = " << count << endl;

    return 0;

}