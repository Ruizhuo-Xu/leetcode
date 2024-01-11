#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> res;
    string path;
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
        if (digits.size() == 0) return res;
        backtracking(digits, 0, mp);
        return res;
    }

    void backtracking(string digits, int startIndex, unordered_map<char, string>& mp) {
        // 时间复杂度: O(3^m * 4^n)， 空间复杂度: O(3^m * 4^n)
        if (path.size() == digits.size()) {
            res.push_back(path);
            return ;
        }
        for (int i = startIndex; i < digits.size(); i++) {
            for (int j = 0; j < mp[digits[i]].size(); j++) {
                path.push_back(mp[digits[i]][j]);
                backtracking(digits, i + 1, mp);
                path.pop_back();
            }
        }
    }
};

int main() {
    string digits = "23";
    vector<string> res = Solution().letterCombinations(digits);
    for (string s : res) {
        cout << s << endl;
    }
    return 0;
}