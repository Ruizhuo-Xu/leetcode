#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2) {
            return false;
        }
        stack<char> record;
        for (int i = 0; i < s.size(); i++) {
            // 匹配到左括号,将对应的右括号入栈,这样后面只要比较当前字符是否和栈顶元素相等即可判断是否匹配
            if (s[i] == '(') record.push(')');
            else if (s[i] == '{') record.push('}');
            else if (s[i] == '[') record.push(']');
            else if (!record.empty() && s[i] == record.top()) record.pop();
            else { // 如果栈为空，或栈顶元素和当前字符不匹配
                return false;
            }
        }
        return record.empty();
    }
};

int main() {
    string s = "(){}[]";
    cout << Solution().isValid(s) << endl;
    return 0;
}