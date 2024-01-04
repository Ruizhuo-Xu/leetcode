#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int, int> mp;
       stack<int> st;
       for (int i = 0; i < nums2.size(); i++) {
            while (!st.empty() && nums2[i] > st.top()) {
                mp[st.top()] = nums2[i]; // 大于st.top()的右边的第一个元素
                st.pop();
            }
            st.push(nums2[i]);
       }
       vector<int> res(nums1.size(), -1);
       for (int i = 0; i < nums1.size(); i++) {
            if (mp.find(nums1[i]) != mp.end()) {
                res[i] = mp[nums1[i]];
            }
       }
       return res;
    }
};

int main() {
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    vector<int> res = Solution().nextGreaterElement(nums1, nums2);
    for (int it : res) {
        cout << it << ' ';
    }
    cout << endl;
    return 0;
}