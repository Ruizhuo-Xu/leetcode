#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int mid = st.top();
                st.pop();
                if (!st.empty() && height[st.top()] > height[mid]) {
                    int left = st.top();
                    int right = i;
                    res += (right - left - 1) * (min(height[left], height[right]) - height[mid]);
                }
            }
            st.push(i);
        }
        return res;
    }
};