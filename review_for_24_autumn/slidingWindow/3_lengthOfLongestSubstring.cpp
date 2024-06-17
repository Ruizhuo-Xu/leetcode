#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char, int> mp;
        int left = 0;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            while (mp[s[i]] > 1) {
                mp[s[left++]]--;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};