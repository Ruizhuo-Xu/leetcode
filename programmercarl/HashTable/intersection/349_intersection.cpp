#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set nums1Set(nums1.begin(), nums1.end());
        unordered_set nums2Set(nums2.begin(), nums2.end());
        vector<int> res;
        for (auto it = nums1Set.begin(); it != nums1Set.end(); it++) {
            if (nums2Set.find(*it) != nums2Set.end()) {
                res.push_back(*it);
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2, 2};
    vector<int> res = Solution().intersection(nums1, nums2);
    for (auto it : res) {
        cout << it << ' ';
    }
    cout << endl;
    return 0;
}