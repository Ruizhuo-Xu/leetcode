#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> maxHeap; // 大顶堆，存放小于中位数的元素
    priority_queue<int, vector<int>, greater<int>> minHeap; // 小顶堆，存放大于中位数的元素
    MedianFinder() {

    }
    
    void addNum(int num) {
        // 这里的重点时动态维持两个堆内元素个数相同，或相差1（奇数情况）,至于是小顶堆多1个还是大顶堆多一个无所谓
        if (maxHeap.size() == minHeap.size()) {
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
        return minHeap.size() == maxHeap.size() ? (minHeap.top() + maxHeap.top()) / 2.0 : maxHeap.top();
    }
};
