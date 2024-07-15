#include <iostream>
#include <vector>
#include <stack>
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
                int height = heights[st.top()];
                st.pop();
                int width = i - st.top() - 1;
                cout << res << endl;
                res = max(res, height * width);
            }
            st.push(i);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {2,1,5,6,2,3};
    cout << Solution().largestRectangleArea(nums) <<endl;
    return 0;
}