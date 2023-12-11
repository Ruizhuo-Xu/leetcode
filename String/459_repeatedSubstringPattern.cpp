#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // 拼接两个s字符串，掐头去尾，如果中间还存在字符串s，则可以由子串重复得到(证明?);
        // t.find(s)使用KMP，时间复杂度O(n+m)
        string t = s + s;
        t.erase(t.begin());
        t.erase(t.end()-1);
        if (t.find(s) != string::npos) return true;
        return false;
    }
};

int main() {
    string s = "abab";
    cout << Solution().repeatedSubstringPattern(s) << endl;
    return 0;
}