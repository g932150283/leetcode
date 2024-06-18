#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findRepeatDocument(vector<int>& documents) {
        int i = 0;
        while (i < documents.size())
        {
            if(documents[i] == i){
                i++;
                continue;
            }
            if(documents[documents[i]] == documents[i]){
                return documents[i];
            }
            swap(documents[i], documents[documents[i]]);
            /* code */
        }
        return -1;
        
    }
};