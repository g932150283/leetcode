#include<bits/stdc++.h>

using namespace std;

// struct Node
// {
//     int val;
//     Node* next;
//     Node(int _val) : val(_val){}
//     /* data */
// };


int main() {
	// 描述：给定两个很大的正整数，用数组A、B表示（A > B），求 A - B 的结果
	// 示例：100056789 - 98765 = 99958024
	int arrA[] = { 1, 0, 0, 0, 5, 6, 7, 8, 9 };
	int arrB[] = { 9, 8, 7, 6, 5 };
	int lenA = sizeof(arrA) / sizeof(arrA[0]);
	int lenB = sizeof(arrB) / sizeof(arrB[0]);
	
	int* largeNumSub(int lenA, int* arrA, int lenB, int* arrB);
	int* result = largeNumSub(lenA, arrA, lenB, arrB);
	return 0;
}
int* largeNumSub(int lenA, int* arrA, int lenB, int* arrB) {
	// todo
    list<int> l1;
    list<int> l2;
    for(int i = lenA - 1; i >= 0; i--){
        l1.push_back(arrA[i]);
    }
    for(int i = lenB - 1; i >= 0; i--){
        l2.push_back(arrB[i]);
    }
    list<int> res;
    for(int i = 0; i < lenA; i++){
        if(!l2.empty()){
            int tmp = l1.front() - l2.front();
            res.push_back(tmp);
            l1.pop_front();
            l2.pop_front();
        }else{
            res.push_back(l1.front());
            l1.pop_front();
        }
    }
    vector<int> nums;
    for(int i = 0; i < lenA; i++){
        if(l1.front() >= 0){
            nums.push_back(l1.front());
            l1.pop_back();
        }else{
            nums.push_back(10 + l1.front());
            l1.pop_back();
            l1.front() = l1.front() - 1;
        }
    }
    reverse(nums.begin(), nums.end());
    
	return nullptr;
}