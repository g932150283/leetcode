#include<bits/stdc++.h>

using namespace std;

/*
比如对于一个有序数组
arr = [1，2，3，3，3，4，5，5，7]，target = 3，那么
*/

// 1.寻找第一个大于 target 的元素的下标，本案例中4  就是第一个大于 target 的元素 ，下标 = 5。
// 如果都不存在，则返回-1
int upper(vector<int> arr, int target){
    // 二分查找规则
    // [l, r]范围，不断缩小范围，直到范围里面只有一个元素
    int l = 0;
    int r = arr.size() - 1;
    if(arr[r] <= target){
        return -1;
    }
    // [l, mid, r]
    while (l < r){
        int mid = (r - l) / 2 + l;
        if(arr[mid] > target){
            r = mid;
        }else if(arr[mid] == target){
            l = mid + 1;
        }else{
            // arr[mid] < target
            l = mid + 1;
        }
    }
    return l;
}

// 如果数组中存在元素等于 target，则返回最后一个等于target 的元素下标，
// 如果不存在，则返回第一个大于 target 的元素下标。
// 本案例中最后一个等于target的下标 = 4。
int floor_upper(vector<int> arr, int target){
    int l = 0;
    int r = arr.size() - 1;
    if(arr[r] <= target){
        return -1;
    }
    
    while (l < r){
        int mid = (r - l) / 2 + l;
        if(arr[mid] > target){
            r = mid;
        }else if(arr[mid] == target){
            l = mid + 1;
        }else{
            // arr[mid] < target
            l = mid + 1;
        }
    }
    if(l - 1 >= 0 && arr[l - 1] == target){
        l--;
    }
    return l;
    //如果都不存在，则返回-1
}

// 寻找最后一个小于 target 的元素的下标，本案例中 2 则是最后一个小于 target 的，下标 = 1.
int lower(vector<int> arr, int target){
    int l = 0;
    int r = arr.size() - 1;
    if(arr[l] >= target){
        return -1;
    }
    
    while (l < r){
        // 整数/2 向下取整
        int mid = (r - l + 1) / 2 + l;
        // [l, mid, r]
        if(arr[mid] > target){
            r = mid - 1;
        }else if(arr[mid] == target){
            r = mid - 1;
        }else{
            // arr[mid] < target
            l = mid;
        }
    }
    // if(l - 1 >= 0 && arr[l - 1] == target){
    //     l--;
    // }
    return l;
//如果都不存在，则返回-1
}

// 如果数组中存在元素等于 target，则返回第一个等于target 的下标，
// 如果不存在，则返回最后一个小于 target 的元素的下标。
// 本案例中第一个等于target的下标 = 2。
int floor_lower(vector<int> arr, int target){
int l = 0;
    int r = arr.size() - 1;
    if(arr[l] > target){
        return -1;
    }
    
    while (l < r){
        // 整数/2 向下取整
        int mid = (r - l + 1) / 2 + l;
        // [l, mid, r]
        if(arr[mid] > target){
            r = mid - 1;
        }else if(arr[mid] == target){
            r = mid - 1;
        }else{
            // arr[mid] < target
            l = mid;
        }
    }
    if(l + 1 < arr.size() && arr[l + 1] == target){
        l++;
    }
    return l;
//如果都不存在，则返回-1
}



int main(){
    vector<int> arr = {1, 2, 3, 3, 3, 4, 5, 5, 7};
    int target = 5;
    cout << "arr = [1，2，3，3，3，4，5，5，7]" << endl;
    cout << "下标= [0，1，2，3，4，5，6，7，8]" << endl;
    cout << "寻找第一个大于 target 的元素的下标 : ,target = " << target << endl;
    cout << upper(arr, target) << endl;
    cout << "如果数组中存在元素等于 target，则返回最后一个等于target 的元素下标，"<< endl;
    cout << "如果不存在，则返回第一个大于 target 的元素下标。target = " << target << endl;
    cout << floor_upper(arr, target) << endl;
    cout << "寻找最后一个小于 target 的元素的下标 : ,target = " << target << endl;
    cout << lower(arr, target) << endl;
    cout << "如果数组中存在元素等于 target，则返回第一个等于target 的下标，"<< endl;
    cout << "如果不存在，则返回最后一个小于 target 的元素的下标。target = " << target << endl;
    cout << floor_lower(arr, target) << endl;
    return 0;
}