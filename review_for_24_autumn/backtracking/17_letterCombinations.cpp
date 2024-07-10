#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> res;
    string s;
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        backtracking(digits, 0, mp);
        return res;
    }

    void backtracking(string digits, int startIdx, unordered_map<char, string>& mp) {
        if (s.size() == digits.size()) {
            res.push_back(s);
            return ;
        }
        int i = startIdx;
        for (int j = 0; j < mp[digits[i]].size(); j++) {
            s.push_back(mp[digits[i]][j]);
            backtracking(digits, i + 1, mp);
            s.pop_back();
        }
    }
};