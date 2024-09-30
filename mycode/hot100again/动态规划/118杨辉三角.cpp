#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        for (int i = 1; i <= numRows; i++)
        {
            if (i == 1)
            {
                res.push_back({1});
                if (i == numRows)
                {
                    break;
                }
            }else if( i == 2){
                res.push_back({1, 1});
                if (i == numRows)
                {
                    break;
                }
            }
            else
            {
                vector<int> v = res[i - 2];
                vector<int> path(i, 1);
                for(int j = 1; j <= i - 2; j++){
                    path[j] = v[j - 1] + v[j];
                }
                res.push_back(path);
            }
        }
        return res;
    }
};