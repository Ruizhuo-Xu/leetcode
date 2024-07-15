#include <iostream>
// #include <queue>
#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    class MyQueue {
    public:
        deque<int> que;
        void push (int val) {
            while (!que.empty() && que.back() < val) {
                que.pop_back();
            }
            que.push_back(val);
        }

        void pop (int val) {
            if (que.front() == val) {
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
            que.pop(nums[i - k]);
            que.push(nums[i]);
            res.push_back(que.front());
        }
        return res;
    }
};