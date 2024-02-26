#include<bits/stdc++.h>

using namespace std;

const int arraySize = 1000;

int arr[arraySize];

int f(int n){
    if(n <= 2){
        return 1;
    }
    return f(n - 1) + f(n - 2);
}

int f1(int n){
    if(n <= 2){
        return 1;
    }

    if(arr[n] != -1){
        return arr[n];
    }else{
        arr[n] = f1(n-1) + f1(n-2);
        return arr[n];
    }
}

int main(){

    for (int i = 0; i < arraySize; ++i) {
        arr[i] = -1;
    }

    for (int  i = 1; i < 10; i++)
    {
        /* code */
        cout << "f(" << i << ") = " << f(i) << endl;
    }
    cout << "*******************" << endl;
    for (int  i = 1; i < 10; i++)
    {
        /* code */
        cout << "f(" << i << ") = " << f1(i) << endl;
    }
    

    return 0;
}