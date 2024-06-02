#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> rec(1000, 0);
        for (int i = 0; i < nums1.size(); i++) {
            rec[nums1[i]]++;
        }
        vector<int> res;
        for (int i = 0; i < nums2.size(); i++) {
            if (rec[nums2[i]] > 0) {
                res.push_back(nums2[i]);
                rec[nums2[i]] = 0;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    vector<int> res = Solution().intersection(nums1, nums2);
    for (int i : res) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}