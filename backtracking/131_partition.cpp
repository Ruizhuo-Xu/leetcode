#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> path;
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return res;
    }

    void backtracking(string s, int startIndex) {
        if (startIndex >= s.size()) { // 递归终止条件,startIndex表示当前子串切割的起点,当startIndex在整个字符串末尾时说明已经到了边界
            res.push_back(path);
            return ;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isPalindrome(s, startIndex, i)) { // startIndex和i组成一个左闭右闭的区间,表示当前分割的子串
                path.push_back(s.substr(startIndex, i - startIndex + 1));
            } else {
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        }
    }

    bool isPalindrome(string s, int startIndex, int endIndex) {
        int left = startIndex;
        int right = endIndex;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    string s = "aab";
    vector<vector<string>> res = Solution().partition(s);
    for (auto it : res) {
        for (string i : it) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}