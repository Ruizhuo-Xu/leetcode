#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 滑动窗口,寻找最长子串问题
        // 尽可能维持一个符合题目条件的窗口,一旦不符合,不断调整窗口,使其符合
        int res = 0;
        unordered_set<char> set;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            while (set.find(s[right]) != set.end()) { // 一旦不符合条件(当前字符在窗口内出现过),则不断调整窗口大小,使其符合条件
                set.erase(s[left]);
                left++;
            }
            set.insert(s[right]);
            res = max(res, right - left + 1); // 记录所有符合条件的窗口的最大长度
        }
        return res;
    }
};

int main() {
    string s = "abcabcbb";
    cout << Solution().lengthOfLongestSubstring(s) << endl;
    return 0;
}