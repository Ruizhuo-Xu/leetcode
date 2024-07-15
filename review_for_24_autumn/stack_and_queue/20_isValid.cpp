#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] =='{') st.push('}');
            else if (s[i] =='[') st.push(']');
            else {
                if (st.empty() || s[i] != st.top()) {  // 一定要考虑栈空的情况
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};