#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> path;
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return res;
    }

    void backtracking(string s, int startIdx) {
        if (startIdx >= s.size()) {
            res.push_back(path);
            return ;
        }
        for (int i = startIdx; i < s.size(); i++) {  // 以[startIdx, i]切割字符串
            if (check(s, startIdx, i)) {
                path.push_back(s.substr(startIdx, i - startIdx + 1));
                backtracking(s, i + 1);
                path.pop_back();
            }
        }
    }

    bool check(string s, int left, int right) {
        for (int i = left, j = right; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};