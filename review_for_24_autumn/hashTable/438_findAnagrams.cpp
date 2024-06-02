#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> hashS(26, 0);
        vector<int> hashP(26, 0);
        for (int i = 0; i < p.size(); i++) {
            hashP[p[i] - 'a']++;
        }
        vector<int> res;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            hashS[s[right] - 'a']++;
            if (right - left + 1 == p.size()) {
                if (hashS == hashP) {
                    res.push_back(left);
                }
                hashS[s[left++] - 'a']--;
            }
        }
        return res;
    }
};

int main() {
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> res = Solution().findAnagrams(s, p);
    for (int i : res) {
        cout << i << endl;
    }
    return 0;
}