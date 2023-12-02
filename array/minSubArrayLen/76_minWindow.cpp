#include <iostream>
#include <string>
#include <cstdint>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_chars;
        unordered_map<char, int> s_chars;
        int t_chars_cnt = 0;
        for (auto it : t) {
            if (t_chars[it] == 0) {
                t_chars_cnt++; // 统计t字符串中不重复的字符个数
            }
            t_chars[it]++; // 统计t字符串中每个字符出现的次数
        }
        int cnt = 0;
        int left = 0;
        int minLength = INT32_MAX;
        int begin = 0; // 最小子序列的起始位置
        for (int right = 0; right < s.size(); right++) {
            if (t_chars[s[right]] > 0) {
                s_chars[s[right]]++;
                if (s_chars[s[right]] == t_chars[s[right]]) {
                    cnt++;
                }
            }
            while (cnt == t_chars_cnt) {
                int subLength = right - left + 1;
                if (subLength < minLength) {
                    minLength = subLength;
                    begin = left;
                }
                if (t_chars[s[left]] > 0) {
                    if (s_chars[s[left]] == t_chars[s[left]]) {
                        cnt--;
                    }
                    s_chars[s[left]]--;
                }
                left++;
            }
        }
        if (minLength == INT32_MAX) {
            return string();
        } else {
            return string(s, begin, minLength);
        }
    }
};

int main() {
    Solution so = Solution();
    // string s = "ADOBECODEBANC", t = "ABC";
    // string s = "aa", t = "aa";
    string s = "cabwefgewcwaefgcf", t = "cae";
    cout << so.minWindow(s, t) << endl;
    return 0;
}