#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, vector<vector<int>>> map; // a+b: [[a, b], [...]]
        for (int i = 0; i < nums.size(); i++) { // 第一次遍历，记录所有两数之和的值及两数的索引
            for (int j = i + 1; j < nums.size(); j++) {
                map[nums[i]+nums[j]].push_back({nums[i], nums[j]});
            }
        }
        unordered_set<vector<int>> res; // 使用unordered_set避免重复的三数组合
        for (int i = 0; i < nums.size(); i++) {
            int gap = -nums[i];
            if (map.find(gap) != map.end()) {
                for (auto it : map[gap]) {
                    if (i != it[0] && i != it[1]) { // 避免重复索引
                        vector<int> temp = {nums[it[0]], nums[it[1]], nums[i]};
                        sort(temp.begin(), temp.end()); // 排序，相同的三数组合排序后相等，然后使用set去除重复
                        res.insert(temp);
                    }
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = Solution().threeSum(nums);
    for (auto it : res) {
        for (auto i : it) {
            cout << i << ' ';
        }
        cout <<endl;
    }
    return 0;
}
