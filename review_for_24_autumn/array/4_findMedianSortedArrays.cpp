#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getKthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int idx1 = 0;
        int idx2 = 0;
        while (true) {
            if (k == 1) {
                return min(nums1[idx1], nums2[idx2]);
            }
            if (idx1 == m) {
                return nums2[idx2 + k - 1];
            }
            if (idx2 == n) {
                return nums1[idx1 + k - 1];
            }
            int newIdx1 = min(idx1 + k / 2 - 1, m - 1);
            int newIdx2 = min(idx2 + k / 2 - 1, n - 1);
            if (nums1[newIdx1] < nums2[newIdx2]) {
                k -= (newIdx1 - idx1 + 1);
                idx1 = newIdx1 + 1;
            } else {
                k -= (newIdx2 - idx2 + 1);
                idx2 = newIdx2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length = nums1.size() + nums2.size();
        if (length % 2 == 1) {
            return getKthElement(nums1, nums2, length / 2 + 1);
        } else {
            return (getKthElement(nums1, nums2, length / 2) + getKthElement(nums1, nums2, length / 2 + 1)) / 2.0;
        }
    }
};