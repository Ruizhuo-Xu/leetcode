#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap; // 小顶堆，存放大于中位数的元素
    priority_queue<int, vector<int>, less<int>> maxHeap; // 大顶堆，存放小于中位数的元素
    MedianFinder() {

    }
    
    void addNum(int num) {
        // 相当于把一个排好序的数组分为两部分，分别用一个小顶堆和一个大顶堆存储；
        // 小顶堆里存的是大于中位数的元素，大顶堆里存的是小于中位数的元素
        // 默认小顶堆元素数量要大于等于大顶堆元素数量
        // 执行插入操作的时候就是先把当前元素插入到另外半边中，再把另外半边的边界元素(堆顶)插入到当前半边
        // 这样就能动态维护这两个堆的大小了
        if (minHeap.size() != maxHeap.size()) {
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        } else {
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        return minHeap.size() != maxHeap.size() ? minHeap.top() : (minHeap.top() + maxHeap.top()) / 2.0;
    }
};