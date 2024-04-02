#include<bits/stdc++.h>

using namespace std;

int main(){
    unordered_map<char, int> umap;
    umap['A'] = 4;
    umap['B'] = 3;
    umap['C'] = 2;
    umap['D'] = 1;
    umap['F'] = 0;
    string s;
    while (getline(cin, s))
    {
        double sum = 0;
        int count = 0;
        int flag = 1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'A'){
                sum += 4;
                count++;
            }else if(s[i] == 'B'){
                sum += 3;
                count++;
            }else if(s[i] == 'C'){
                sum += 2;
                count++;
            }else if(s[i] == 'D'){
                sum += 1;
                count++;
            }else if(s[i] == 'F'){
                sum += 0;
                count++;
            }else if(s[i] == ' '){
                continue;
            }else{
                flag = 0;
                cout << "Unknown" << endl;
                break;
            }
        }
        if(flag){
            printf("%.2f/n", sum / count);
        }

        /* code */
    }
    




    return 0;
}