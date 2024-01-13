#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    struct Cmp {
        bool operator () (pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second; // 小顶堆
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 时间复杂度: O(nlogk)
        // 空间复杂度: O(n)
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++; // 统计每个数字出现的频率
        }
        priority_queue<pair<int, int>, vector<pair<int,int>>, Cmp> que;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            que.push(*it);
            if (que.size() > k) {
                que.pop();
            }
        }
        vector<int> res;
        while (!que.empty()) {
            res.push_back(que.top().first);
            que.pop();
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> res = Solution().topKFrequent(nums, 2);
    for (int num : res) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}