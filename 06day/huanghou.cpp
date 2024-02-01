#include<bits/stdc++.h>

using namespace std;


class Solution
{
private:
    /* data */
public:
    Solution(/* args */){};

    const static int N = 8;

    void queenSettle(vector<int>& selectColumns, int row){
        if(row > N - 1){
            printQueens(selectColumns);
            return;
        }

        for(int i = 0; i < N; i++){
            if(!isValid(row, i, selectColumns)){
                continue;
            }
            selectColumns[row] = i;
            queenSettle(selectColumns, row + 1);

            selectColumns[row] = -1;
        }
    }

    bool isValid(int row, int column, vector<int>& selectColumns){
        int leftup = column - 1;
        int rightup = column + 1;
        for(int i = row - 1; i >= 0; i--){
            if(selectColumns[i] == column){
                return false;
            }
            if(leftup >= 0){
                if(selectColumns[i] == leftup){
                    return false;
                }
            }
            if(rightup < 8){
                if(selectColumns[i] == rightup){
                    return false;
                }
            }
            leftup--;
            rightup++;
        }
        return true;
    }

    void printQueens(vector<int>& result) { // 打印出一个二维矩阵
        for (int row = 0; row < 8; ++row) {
            for (int column = 0; column < 8; ++column) {
                if (result[row] == column){
                    cout << "Q ";
                }else{
                    cout << "* ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }

};


int main(){
    Solution s;
    vector<int> s1(8, -1);
    s.queenSettle(s1, 0);

    return 0;
}

