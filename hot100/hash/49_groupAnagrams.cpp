#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 时间复杂度O(nklogk), n是字符串数组的长度,k是每个字符串的长度
        // 空间复杂度O(nk)
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end()); // klog(k)
            mp[str].push_back(strs[i]);
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
    for (auto it : res) {
        for (auto str : it) {
            cout << str << ' ';
        }
        cout << endl;
    }
    return 0;
}