#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // int recordP[26] = {0};
        vector<int> recordP(26); // 使用vector<int>，方便后续直接使用==操作符
        for (int i = 0; i < p.size(); i++) {
            recordP[p[i] - 'a']++;
        }
        // int recordS[26] = {0};
        vector<int> recordS(26);
        // int isFind = true;
        vector<int> res;
        for (int i = 0; i < s.size(); i++) {
            recordS[s[i] - 'a']++;
            if (i >= p.size() - 1) {
                // for (int j = 0; j < 26; j++) {
                //     if (recordP[j] != recordS[j]) {
                //         isFind = false;
                //         break;
                //     } else {
                //         isFind = true;
                //     }
                // }
                // if (isFind) {
                //     res.push_back(i - p.size() + 1);
                // }
                if (recordP == recordS) { // 使用==操作符替代上面的操作
                    res.push_back(i - p.size() + 1);
                }
                recordS[s[i - p.size() + 1] - 'a']--;
            }
        }
        return res;
    }
};

int main() {
    string s = "cbaebabacd", p = "abc";
    vector<int> res = Solution().findAnagrams(s, p);
    for (auto it : res) {
        cout << it << ' ';
    }
    cout << endl;
    return 0;
}