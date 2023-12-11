#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) { //strStr的返回
            return 0;
        }
        vector<int> next(needle.size());
        // 获取前缀表
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) j++;
            if (j == needle.size()) {
                return (i - j + 1);
            }
        }
        return -1;
    }

    void getNext(vector<int>& next, const string& s) {
        // 给定一个字符串s，返回前缀表
        // 初始化
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++) { // 由于已经初始化了next[0]，所以i从1开始
            while (j > 0 && s[j] != s[i]) {
                // 如果当前前缀子串(s)的最后一个字母和后缀子串(e)最后一个字母不相等
                // 则利用已有的前缀表[0,j-1]进行跳转,直到匹配为止，或j到达起始位置
                // s[:-1] = e[:-1], s[:next[j-1]-1] = s[-next[j-1]:-1] = e[:next[j-1]-1] = e[-next[j-1]:-1]
                // 相当于前缀子串保留部分已经匹配的前缀部分向前收缩，后缀子串保留相应匹配的后缀部分向后收缩
                j = next[j - 1];
            }
            // j的位置表示的是当前要比较(是否相等)的前后缀字符串中前缀子串末尾的位置
            // i的位置是后缀子串末尾的位置
            // j之前的前缀子串和i之前的后缀子串已经匹配(相等)
            if (s[i] == s[j]) j++;
            // j的值表示的是i之前(包括i)的子串的最大相等前后缀长度
            next[i] = j;
        }
    }
};

int main() {
    string haystack = "aabaabaafa";
    string needle = "aabaaf";
    cout << Solution().strStr(haystack, needle) << endl;
    return 0;
}