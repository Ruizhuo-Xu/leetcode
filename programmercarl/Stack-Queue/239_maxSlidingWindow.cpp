#include <iostream>
#include <vector>
#include <deque>
#include <cstdint>
using namespace std;

class Solution {
private:
    // 使用一个双向队列来维护滑动窗口,队列的长度<=k
    // 要保证队列中的元素在窗口滑动的过程中都有可能成为最大值,所以要保证队列单调不递增
    // 队首位置元素表示当前窗口中的最大值
    class MyQueue {
    public:
        deque<int> que;
        // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
        // 同时pop之前判断队列当前是否为空。
        void pop(int val) {
            if (!que.empty() && que.front() == val) {
                que.pop_front();
            }
        }
        // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
        // 这样就保持了队列里的数值是单调从大到小的了。
        void push(int val) {
            while (!que.empty() && val > que.back()) {
                que.pop_back();
            }
            que.push_back(val);
        }
        // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
        int front() {
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> res;
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        res.push_back(que.front());  // 记录前k个元素的最大值
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);
            que.push(nums[i]);
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