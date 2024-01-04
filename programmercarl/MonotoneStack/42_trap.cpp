#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // 使用单调栈找到数组右边第一个大于栈顶元素的位置,栈顶元素弹出后,新的栈顶元素是数组左边第一个大于弹出栈顶元素的位置,两者构成接雨水的区域
        stack<int> st;
        int sum = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int mid = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
                int left = st.top();
                // st.pop(); // 这里不能弹出,否则会漏
                sum += (i - left - 1) * (min(height[i], height[left]) - height[mid]);
            }
            st.push(i);
        }
        return sum;
    }
};

int main() {
    // vector<int> h = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> h = {4,2,0,3,2,5};
    cout << Solution().trap(h) << endl;
    return 0;
}