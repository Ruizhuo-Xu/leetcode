#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:
    class MyComparistion {
    public:
        // 小顶堆
        bool operator() (pair<int, int> a, pair<int, int> b) {
            return a.second > b.second; // ??
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int it : nums) {
            mp[it]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyComparistion> que;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            que.push(*it);
            if (que.size() > k) {
                que.pop();
            }
        }
        vector<int> res(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i] = que.top().first;
            que.pop();
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> res = Solution().topKFrequent(nums, k);
    for (int it : res) {
        cout << it << ' ';
    }
    cout << endl;
    return 0;
}