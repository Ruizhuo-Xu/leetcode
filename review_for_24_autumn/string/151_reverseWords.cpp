#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // 首先整体反转，然后反转每个单词 (先使用双指针去掉不合法的空格：前后都是字母的空格是合法空格)
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            // 双指针删除所有空格，左指针指向去除空格后的新数组，右指针遍历老数组，遇到空格则继续遍历，遇到非空格则赋值给新数组（本题特殊要求要插入一个空格）
            if (s[right] != ' ') {
                if (left != 0) {
                    s[left++] = ' ';  // 每个单词前插入一个空格，除了第一个单词
                }
                while (right < s.size() && s[right] != ' ') {
                    s[left++] = s[right++];
                }
            }
        }
        s.resize(left);
        reverse(s.begin(), s.end());
        left = 0;
        for (int right = 0; right < s.size(); right++) {
            if (s[right] == ' ') {
                reverse(s.begin() + left, s.begin() + right);
                left = right + 1;
            }
            if (right == s.size() - 1) {  // 最后一个单词
                reverse(s.begin() + left, s.end());
            }
        }
        return s;
    }
};

int main() {
    // string s = "  a    good   example  ";
    string s = "the sky is blue";
    cout << Solution().reverseWords(s) << '1';
    return 0;
}