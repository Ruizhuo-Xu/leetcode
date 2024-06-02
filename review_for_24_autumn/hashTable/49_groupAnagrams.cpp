#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(strs[i]);  // 记录原始的字符串
        }
        vector<vector<string>> res;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = Solution().groupAnagrams(strs);
    for (vector<string> x : res) {
        for (string xi : x) {
            cout << xi << ' ';
        }
        cout << endl;
    }
    return 0;
}