#include <iostream>
#include <vector>
#include <string>
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
        if (path.size() == 2*n) {
            if (leftNum == 0) {
                res.push_back(path);
            }
            return ;
        }
        vector<char> chars = {'(', ')'};
        int newLeftNum = 0;
        for (int i = 0; i < 2; i++) {
            if (chars[i] == '(') newLeftNum = leftNum + 1;
            else if (chars[i] == ')') newLeftNum = leftNum - 1;
            if (newLeftNum < 0 || newLeftNum > n) continue;
            path.push_back(chars[i]);
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