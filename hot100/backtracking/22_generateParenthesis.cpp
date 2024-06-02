#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> res;
    string path;
    vector<string> generateParenthesis(int n) {
        backtracking(n, 0);
        return res;
    }

    void backtracking(int n, int leftNum) {
        if (leftNum > 2 * n - path.size()) {
            // 剪枝，因为左右括号匹配，所以所需的右括号的数量等于左括号的数量
            // 如果所需的右括号的数量 > 剩余最大右括号的数量(剩余的位置全取右括号),说明当前字符串括号不可能匹配
            return ;
        }
        if (path.size() == 2 * n) { // 当字符串的长度==2n说明已经是完整的字符串了
            res.push_back(path);
            return ;
        }
        vector<char> chars = {'(', ')'};
        int newLeftNum = 0;
        for (char c : chars) { // 每次2选一
            if (c == '(') newLeftNum = leftNum + 1;
            else if (c == ')') newLeftNum = leftNum - 1;
            if (newLeftNum < 0 || newLeftNum > n) continue; // 左括号数量不符合条件
            path.push_back(c);
            backtracking(n, newLeftNum);
            path.pop_back();
        }
    }
};

int main() {
    vector<string> res = Solution().generateParenthesis(3);
    for (string s : res) {
        cout << s << endl;
    }
    return 0;
}