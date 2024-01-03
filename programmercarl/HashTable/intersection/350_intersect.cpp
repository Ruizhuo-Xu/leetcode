#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums1Map;
        for (int i = 0; i < nums1.size(); i++) {
            nums1Map[nums1[i]]++;
        }
        vector<int> res;
        for (int i = 0; i < nums2.size(); i++) {
            if (nums1Map[nums2[i]] > 0) {
                res.push_back(nums2[i]);
                nums1Map[nums2[i]]--;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {4, 9, 9, 8, 4};
    vector<int> res = Solution().intersect(nums1, nums2);
    for (auto it : res) {
        cout << it << ' ';
    }
    cout << endl;
    return 0;
}