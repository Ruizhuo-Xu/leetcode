#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(target - nums[i]) != mp.end()) {
                res.push_back(i);
                res.push_back(mp[target - nums[i]]);
            }
            mp[nums[i]] = i;
        }
        return res;
    }
};

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 22;
    vector<int> res = Solution().twoSum(nums, target);
    for (int i : res) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}