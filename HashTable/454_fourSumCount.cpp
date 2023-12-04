#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map; // num1+num2 : cnt
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                int sum = nums1[i] + nums2[j];
                map[sum]++; // 统计每个加和出现的次数
            }
        }
        int cnt = 0;
        for (int i = 0; i < nums3.size(); i++) {
            for (int j = 0; j < nums4.size(); j++) {
                int sum = nums3[i] + nums4[j];
                int gap = -sum;
                if (map.find(gap) != map.end()) {
                    cnt += map[gap];
                }
            }
        }
        return cnt;
    }
};

int main() {
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {-1,-2};
    vector<int> nums3 = {-1, 2};
    vector<int> nums4 = {0, 2};
    cout << Solution().fourSumCount(nums1, nums2, nums3, nums4) << endl;
    return 0;
}