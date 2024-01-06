#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool check(unordered_map<char, int>& hashT, unordered_map<char, int>& hashS) {
        for (auto it = hashT.begin(); it != hashT.end(); it++) {
            if (it->second > hashS[it->first]) { // 说明当前t中的某个字符数量大于s子串中该字符的数量
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        // 滑动窗口找最小子串问题:
        // 移动right指针寻找符合条件的滑动窗口
        // 找到后,在保持条件满足的情况下,移动left指针,不断收缩窗口,寻找最小的符合条件的窗口
        // 使用哈希表判断s的子串中是否包含t中所有的字符
        // 时间复杂度O(Cn + m),空间复杂度O(C),C表示字符的种类
        unordered_map<char, int> hashT;
        for (int i = 0; i < t.size(); i++) {
            hashT[t[i]]++;
        }
        unordered_map<char, int> hashS;
        int left = 0;
        int minVal = INT32_MAX;
        int startIndex = -1;
        for (int right = 0; right < s.size(); right++) {
            hashS[s[right]]++;
            while (check(hashT, hashS) && left <= right) {
                if (right - left + 1 < minVal) {
                    minVal = right - left + 1;
                    startIndex = left;
                }
                hashS[s[left]]--;
                left++;
            }
        }
        return startIndex >= 0 ? s.substr(startIndex, minVal) : ""; // 起始位置, 子串长度
    }
};

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << Solution().minWindow(s, t) << endl;
    return 0;
}