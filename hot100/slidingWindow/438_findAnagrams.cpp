#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // 字母异位词,可以用排序或者哈希表来判断，哈希表考虑用数组(26个字母)来表示
        // 时间复杂度O(26n), 空间复杂度O(1)
        vector<int> hashP(26, 0);
        for (int i = 0; i < p.size(); i++) {
            hashP[p[i] - 'a']++;
        }
        vector<int> hashS(26, 0);
        vector<int> res;
        for (int i = 0; i < s.size(); i++) {
            hashS[s[i] - 'a']++;
            if (i >= p.size() - 1) { // 维持一个长度和p相等的滑动窗口
                if (hashS == hashP) { // 两个vector可以直接==比较元素是否相同
                    res.push_back(i - p.size() + 1); // 记录起始位置
                }
                hashS[s[i - p.size() + 1] - 'a']--;
            }
        }
        return res;
    }
};

int main() {
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> res = Solution().findAnagrams(s, p);
    for (int it : res) {
        cout << it << ' ';
    }
    cout << endl;
    return 0;
}