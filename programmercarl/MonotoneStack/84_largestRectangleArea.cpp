#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> st;
        // 头尾分别加一个0,考虑8,6,4,2和2,4,6,8两种情况
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int mid = st.top();
                st.pop();
                int left = st.top();
                res = max(res, (i - left - 1) * heights[mid]);
            }
            st.push(i);
        }
        return res;
    }
};

int main() {
    vector<int> h = {2,1,5,6,2,3};
    cout << Solution().largestRectangleArea(h) << endl;
    return 0;
}