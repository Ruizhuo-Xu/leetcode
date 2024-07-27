#include <iostream>
#include <vector>
using namesapce std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> mp(26, -1);  // 每个字母最远出现的位置
        for (int i = 0; i < s.size(); i++) {
            mp[s[i] - 'a'] = max(mp[s[i] - 'a'], i);
        }
        vector<int> res;
        int maxIdx = -1;
        int startIdx = 0;
        for (int i = 0; i < s.size(); i++) {
            maxIdx = max(maxIdx, mp[s[i] - 'a']);
            if (i == maxIdx) {
                res.push_back(i - startIdx + 1);
                startIdx = i + 1;
            }
        }
        return res;
    }
};