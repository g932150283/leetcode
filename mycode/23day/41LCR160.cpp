#include<bits/stdc++.h>

using namespace std;

// priority_queue<Type, Container, Functional>
// Type为数据类型， Container为保存数据的容器，Functional为元素比较方式。
// 如果不写后两个参数，那么容器默认用的是vector，比较方式默认用operator<，也就是优先队列是大顶堆，队头元素最大。


class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int>> A; // 小顶堆，保存较大的一半
    priority_queue<int, vector<int>, less<int>> B; // 大顶堆，保存较小的一半
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(A.size() != B.size()){
            A.emplace(num);
            B.emplace(A.top());
            A.pop();
        }else{
            B.emplace(num);
            A.emplace(B.top());
            B.pop();
        }
    }
    
    double findMedian() {
        if(A.size() == B.size()){
            return (A.top() + B.top()) / 2.0;
        }else{
            return A.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */