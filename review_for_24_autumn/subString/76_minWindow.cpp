#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool check(unordered_map<char, int>& mpS, unordered_map<char, int>& mpT) {
        for (auto it = mpT.begin(); it != mpT.end(); it++) {
            if (mpS.find(it->first) == mpS.end() || mpS[it->first] < it->second) {  // 这里是小于，s涵盖t
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> mpT;
        unordered_map<char, int> mpS;
        for (int i = 0; i < t.size(); i++) {
            mpT[t[i]]++;
        }
        int res = INT32_MAX;
        int begin = -1;
        int left = 0;
        for (int i = 0; i < s.size(); i++) {
            mpS[s[i]]++;
            while (check(mpS, mpT)) {
                if (i - left + 1 < res) {
                    res = i - left + 1;
                    begin = left;
                }
                mpS[s[left++]]--;
            }
        }
        return begin == -1 ? "" : s.substr(begin, res);
    }
};