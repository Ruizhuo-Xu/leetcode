#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        bakctracking(nums, 0);
        return res;
    }

    void bakctracking(vector<int>& nums, int startIdx) {
        if (path.size() > 1) {
            res.push_back(path);
        }
        unordered_set<int> set;
        for (int i = startIdx; i < nums.size(); i++) {
            if (set.find(nums[i]) == set.end() && (path.size() > 0 && nums[i] >= path[path.size() - 1] || path.size() == 0)) {
                set.insert(nums[i]);
                path.push_back(nums[i]);
                bakctracking(nums, i + 1);
                path.pop_back();
            }
        }
    }
};

int main() {
    // vector<int> nums = {1,2,3,4,5,6,7,8,9,10,1,1,1,1,1};
    vector<int> nums = {4, 6, 7, 6};
    vector<vector<int>> res = Solution().findSubsequences(nums);
    for (vector<int> x : res) {
        for (int i : x) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}