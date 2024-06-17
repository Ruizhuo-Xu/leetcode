#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) {
            return {};
        }
        vector<int> cntP(26, 0);
        vector<int> cntS(26, 0);
        for (int i = 0; i < p.size(); i++) {
            cntP[p[i] - 'a']++;
            cntS[s[i] - 'a']++;
        }
        vector<int> res;
        if (cntP == cntS) {
            res.push_back(0);
        }
        int left = 0;
        for (int i = p.size(); i < s.size(); i++) {
            cntS[s[i] - 'a']++;
            cntS[s[left++] - 'a']--;
            if (cntP == cntS) {
                res.push_back(left);
            }
        }
        return res;
    }
};