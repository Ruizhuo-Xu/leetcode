#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // 单调栈:通常是一维数组，要寻找任一个元素的右边或者左边第一个比自己大或者小的元素的位置，此时我们就要想到可以用单调栈了
        // 单调栈的本质是空间换时间,更直白来说，就是用一个栈来记录我们遍历过的元素
        // 时间复杂度O(n),空间复杂度O(n)
        stack<int> st;
        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            if (st.empty()) st.push(i); // 栈为空,直接入栈
            else {
                if (temperatures[i] <= temperatures[st.top()]) { // 维持一个递增的单调栈(栈顶元素最小)
                    st.push(i);
                } else {
                    while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                        res[st.top()] = i - st.top();
                        st.pop();
                    }
                    st.push(i); // 弹出比当前元素小的元素后,将当前元素入栈
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> t = {73,74,75,71,69,72,76,73};
    vector<int> res = Solution().dailyTemperatures(t);
    for (int it : res) {
        cout << it << ' ';
    }
    cout << endl;
    return 0;
}