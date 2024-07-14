#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string path;
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        backtracking(n, 0);
        return res;
    }

    void backtracking(int n, int leftNum) {
        // leftNum表示的是当前层初始有效的左括号数量(左括号+1, 右括号-1)
        // 如果leftNum < 0, 说明必有右括号数量>左括号数量, 不是有效的组合
        // 2 * n - path.size()表示剩余的可选的括号数,如果leftNum超过这个数的话，说明后续不管怎么选都无法满足要求
        if (path.size() == 2 * n) {
            res.push_back(path);
            return ;
        }
        vector<char> chs = {'(', ')'};
        for (char c : chs) {
            int newLeftNum = leftNum;  // 这里要新建一个变量
            if (c == '(') {
                newLeftNum++;
            } else {
                newLeftNum--;
            }
            if (leftNum < 0 || newLeftNum > 2 * n - (int) path.size()) {
                continue;
            }
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