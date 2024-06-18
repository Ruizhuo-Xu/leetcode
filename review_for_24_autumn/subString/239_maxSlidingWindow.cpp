#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    class MyQueue {
    public:
        deque<int> que;  // 双向队列, 想象从右进,左右都可以出 (左为front)
        void push(int val) {
            while (!que.empty() && val > que.back()) {
                que.pop_back();
            }
            que.push_back(val);
        }

        void pop(int val) {
            if (que.front() == val) {  // 这里容易出错，容易把条件想为 que.size() >= k, 这是不对的, 反例 1 3 1 2 0 5
                // 这里容易产生的疑问：当这个条件成立时，que.front()一定是i - k位置的元素吗？不能是其他位置但是值相同吗？
                // 可以从队列出队的逻辑思考,队列有两种出队方式: 1.入队时，维持单调队列，需要将不符合条件的元素出队；2. 调用pop出队，弹出老元素
                // 对于第一种情况，如果i-k位置的元素已经出队了,那么和他值相同的元素都会出队；对于第二种情况，正是符合我们期望的方式； 
                que.pop_front();
            }
        }

        int front() {
            return que.front();
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        vector<int> res;
        res.push_back(que.front());
        for (int i = k; i < nums.size(); i++) {
            // 维持一个滑动窗口, 弹出老元素，压入新元素
            que.pop(nums[i - k]);
            que.push(nums[i]);
            res.push_back(que.front());
        }
        return res;
    }
};