#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsets(vector<int>& nums) {
        res.push_back({});
        backtracking(nums, 0);
        return res;
    }

    void backtracking(vector<int> nums, int startIndex) {
        if (startIndex == nums.size()) {
            return ;
        }
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            res.push_back(path);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
};

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = Solution().subsets(nums);
    for (auto it : res) {
        for (int i : it) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}