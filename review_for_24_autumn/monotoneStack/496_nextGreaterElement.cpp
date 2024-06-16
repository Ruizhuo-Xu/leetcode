#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums2.size(); i++) {
            mp[nums2[i]] = i;
        }
        stack<int> st;
        vector<int> temp(nums2.size(), -1);
        for (int i = 0; i < nums2.size(); i++) {
            while (!st.empty() && nums2[i] > nums2[st.top()]) {
                temp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        vector<int> res(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++) {
            res[i] = temp[mp[nums1[i]]];
        }
        return res;
    }
};