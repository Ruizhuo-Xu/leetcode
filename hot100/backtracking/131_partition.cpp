#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return res;
    }

    void backtracking(string s, int startIndex) {
        if (startIndex == s.size()) {
            res.push_back(path);
            return ;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (check(s, startIndex, i)) {
                path.push_back(s.substr(startIndex, i - startIndex + 1));
            } else {
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        }
    }

    bool check(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};

int main() {
    string s = "aab";
    vector<vector<string>> res = Solution().partition(s);
    for (auto strs : res) {
        for (auto str : strs) {
            cout << str << ' ';
        }
        cout << endl;
    }
    return 0;
}