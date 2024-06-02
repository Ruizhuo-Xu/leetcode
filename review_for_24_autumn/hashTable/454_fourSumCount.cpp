#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                mp[nums1[i] + nums2[j]]++;
            }
        }
        int res = 0;
        for (int i = 0; i < nums3.size(); i++) {
            for (int j = 0; j < nums4.size(); j++) {
                if (mp.find(-(nums3[i] + nums4[j])) != mp.end()) {
                    res += mp[-(nums3[i] + nums4[j])];
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums1 = {1,2}, nums2 = {-2,-1}, nums3 = {-1,2}, nums4 = {0,2};
    cout << Solution().fourSumCount(nums1, nums2, nums3, nums4) << endl;
    return 0;
}