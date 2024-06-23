#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());
        int shift = k % nums.size();
        reverse(nums.begin(), nums.begin() + shift);
        reverse(nums.begin() + shift, nums.end());
    }
};