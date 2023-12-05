#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // 先去除多余的空格，归一化字符串
        // 翻转整个字符串
        // 翻转字符串中的每个单词(翻转子字符串)
        removeSpace(s);
        reverse(s, 0, s.size() - 1);
        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j <= s.size(); j++) {
                if (j == s.size() || s[j] == ' ') {
                    reverse(s, i, j - 1);
                    i = j;
                    break;
                }
            }
        }
        return s;
    }

    void removeSpace(string& s) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < s.size(); fastIndex++) {
            if (s[fastIndex] != ' ') {
                s[slowIndex++] = s[fastIndex];
            } else if (fastIndex > 0 && s[fastIndex] == ' ' && s[fastIndex - 1] != ' ') {
                s[slowIndex++] = s[fastIndex];
            }
        }
        if (s[slowIndex - 1] == ' ') {
            slowIndex--;
        }
        return s.resize(slowIndex);
    }
    
    void reverse(string& s, int begin, int end) {
        while (begin < end) {
            swap(s[begin], s[end]);
            begin++;
            end--;
        }
    }
};

int main() {
    // string s = "   a  good  example   ";
    string s = "the sky is blue";
    cout << Solution().reverseWords(s) << endl;
    return 0;
}