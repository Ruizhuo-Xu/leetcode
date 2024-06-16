#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> res(nums.size(), -1);
        for (int i = 0; i < nums.size() * 2; i++) {
            while (!st.empty() && nums[i % nums.size()] > nums[st.top() % nums.size()]) {
                if (st.top() < nums.size())
                    res[st.top()] = nums[i % nums.size()];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};