#include <iostream>
#include <vector>
#include <deque> // deque
using namespace std;

class Solution {
private:
    class MyQueue {
    public:
        deque<int> que;
        void pop(int val) { // 维持队列大小
            if (que.front() == val) {
                que.pop_front();
            }
        }
        void push(int val) {
            while (!que.empty() && que.back() < val) { // 维持一个单调不递增的队列
                que.pop_back();
            }
            que.push_back(val);
        }
        int front() {
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 维持一个单调队列
        // 每个元素只会入队出队一次,所以时间复杂度是O(n), 空间复杂度O(n)
        MyQueue que;
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        vector<int> res;
        res.push_back(que.front());
        for (int i = k; i < nums.size(); i++) {
            que.push(nums[i]);
            que.pop(nums[i - k]);
            res.push_back(que.front());
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = Solution().maxSlidingWindow(nums, k);
    for (int it : res) {
        cout << it << ' ';
    }
    cout << endl;
    return 0;
}