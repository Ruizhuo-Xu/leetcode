#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<char> st;;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ']') {
                string subStr;
                while (!st.empty() && st.top() != '[') {
                    subStr += st.top();
                    st.pop();
                }
                st.pop();  // 弹出左括号
                int num = 0;
                int factor = 1;
                while (!st.empty() && st.top() >= '0' && st.top() <= '9') {
                    num += (st.top() - '0') * factor;
                    factor *= 10;
                    st.pop();
                }
                while (num--) {
                    for (int j = (int) subStr.size() - 1; j >= 0; j--) {
                        st.push(subStr[j]);
                    }
                }
            } else {
                st.push(s[i]);
            }
        }
        string res = "";
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
    string res = Solution().decodeString(s);
    cout << res << endl;
    return 0;
}