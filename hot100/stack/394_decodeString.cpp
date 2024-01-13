#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']') { // 除了右括号，其他字符都入栈
                st.push(s[i]);
            } else { 
                string str;
                while (!st.empty() && st.top() != '[') { // 弹出括号内的字符
                    str.push_back(st.top());
                    st.pop();
                }
                st.pop(); // 弹出左括号
                string numStr;
                while (!st.empty() && st.top() >= '0' && st.top() <= '9') { // 弹出需要重复的次数
                    numStr.push_back(st.top());
                    st.pop();
                }
                reverse(numStr.begin(), numStr.end());
                int num = stoi(numStr);
                while (num--) { // 重复括号内的字符并重新入栈
                    for (int i = str.size() - 1; i >= 0; i--) {
                        st.push(str[i]);
                    }
                }
            }
        }
        string res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    string s = "3[a2[c]]";
    cout << Solution().decodeString(s) << endl;
    return 0;
}