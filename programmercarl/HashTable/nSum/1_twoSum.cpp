#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 当我们需要查询一个元素是否出现过，或者一个元素是否在集合里的时候，就要第一时间想到哈希法
        // 查找一个元素使用二分法时间复杂度是O(logn),查找n个元素是O(nlogn),空间复杂度都是O(1)
        // 查找一个元素构建并使用哈希表时间复杂度是O(n)(构建需要过一遍数据), 查找n个元素还是O(n)(只需要过一遍数据),空间复杂度都是O(n)
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i + 1; // 建立value: index的映射
        }
        for (int i = 0; i < nums.size(); i++) {
            int gap = target - nums[i];
            if (mp[gap] > 0 && (mp[gap] - 1) != i) { // 注意将自身排除,数组中同一个元素在答案里不能重复出现
                return vector<int>{i, mp[gap] - 1};
            }
        }
        return vector<int>{};
    }
};

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 单循环
        // 当我们需要查询一个元素是否出现过，或者一个元素是否在集合里的时候，就要第一时间想到哈希法
        // 查找一个元素使用二分法时间复杂度是O(logn),查找n个元素是O(nlogn),空间复杂度都是O(1)
        // 查找一个元素构建并使用哈希表时间复杂度是O(n)(构建需要过一遍数据), 查找n个元素还是O(n)(只需要过一遍数据),空间复杂度都是O(n)
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int gap = target - nums[i];
            auto it = mp.find(gap);
            if (it != mp.end()) {
                return vector<int>{i, it->second};
            }
            mp[nums[i]] = i; // 建立value: index的映射
        }
        return vector<int>{};
    }
};

int main() {
    vector<int> nums = {3, 2, 4};
    int target = 6;
    vector<int> res = Solution1().twoSum(nums, target);
    for (auto it : res) {
        cout << it << ' ';
    }
    cout << endl;
    return 0;
}