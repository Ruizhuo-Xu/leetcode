#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    struct cmp {
        bool operator () (pair<int, int>& x1, pair<int, int>& x2) {
            return x1.second > x2.second;  // 小顶堆
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;
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