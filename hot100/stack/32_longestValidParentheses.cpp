#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // 保证栈底元素始终为未匹配的右括号下标,其他元素为左括号下标
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') { // 左括号直接入栈
                st.push(i);
            } else {
                st.pop(); // 遇到右括号就将栈顶元素弹出
                if (st.empty()) { // 弹出后栈空说明弹出的是栈底元素，即未匹配的右括号
                    st.push(i); // 将当前的右括号入栈，作为栈底元素
                } else { // 否则，弹出的是匹配的左括号, 有效的字符串长度为i - st.top()
                    res = max(res, i - st.top());
                }
            }
        }
        return res;
    }
};

int main() {
    string s = "((()()())";
    cout << Solution().longestValidParentheses(s) << endl;
    return 0;
}