#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '[') st.push(']');
            else if (s[i] == '{') st.push('}');
            else {
                if (st.empty() || st.top() != s[i]) { // 如果栈为空或括号不匹配
                    return false;
                } else { // 匹配，弹出栈顶元素
                    st.pop();
                }
            }
        }
        return st.empty(); // 全部匹配，栈为空
    }
};

int main() {
    string s = "()[]{}";
    cout << Solution().isValid(s) << endl;
    return 0;
}