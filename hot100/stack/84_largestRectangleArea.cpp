#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int mid = st.top();
                st.pop();
                int left = st.top();
                int right = i;
                res = max(res, (right - left - 1) * heights[mid]);
            }
            st.push(i);
        }
        return res;
    }
};

int main() {
    vector<int> heights = {2,1,5,6,2,3};
    cout << Solution().largestRectangleArea(heights) << endl;
    return 0;
}