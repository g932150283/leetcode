#include <bits/stdc++.h>

using namespace std;


int main(){


    set<vector<long>> s;
    vector<long> l1 = {1, 2};
    vector<long> l2 = {2, 1};
    vector<long> l3 = l2;
    sort(l3.begin(), l3.end());

    s.insert(l1);
    s.insert(l3);
    cout << s.size() << endl;


    return 0;
}