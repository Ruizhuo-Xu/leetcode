#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
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
        if (digits.empty()) { // 如果这里不加这个判断,当digits为空时,进入下面的递归,会返回{""},应该返回{}
            return res;
        }
        backtracking(digits, 0, mp);
        return res;
    }

    void backtracking(string digits, int digitIndex, unordered_map<char, string> mp) {
        if (path.size() == digits.size()) {
            res.push_back(path);
            return ;
        }
        string chars = mp[digits[digitIndex]];
        for (int i = 0; i < chars.size(); i++) {
            path.push_back(chars[i]);
            backtracking(digits, digitIndex + 1, mp);
            path.pop_back();
        }
    }
};

int main() {
    string digits = "23";
    vector<string> res = Solution().letterCombinations(digits);
    for (string it : res) {
        cout << it << endl;
    }
    return 0;
}