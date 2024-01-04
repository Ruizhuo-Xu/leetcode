#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 时间复杂度O(n),空间复杂度O(n)
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int>::iterator it = mp.find(target - nums[i]); // 类型也可以用auto
            if (it != mp.end()) {
                return {it->second, i};
            }
            mp[nums[i]] = i;
            // mp.insert({nums[i], i}); // insert里面要用{}
        }
        return {};
    }
};

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> res = Solution().twoSum(nums, target);
    for (int it : res) {
        cout << it << ' ';
    }
    cout << endl;
    return 0;
}