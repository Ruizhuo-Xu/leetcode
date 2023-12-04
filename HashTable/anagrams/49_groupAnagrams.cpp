#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include<algorithm>
using namespace std;

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> res = {};
//         int cnt = 0; // 统计当前groups的数目
//         bool isInPreGroup = false;
//         for (int i = 0; i < strs.size(); i++) {
//             int loop = cnt;
//             while (loop--) {
//                 if (isAnagrams(res[loop][0], strs[i])) {
//                     res[loop].push_back(strs[i]);
//                     isInPreGroup = true;
//                     break;
//                 }
//             }
//             if (isInPreGroup) {
//                 isInPreGroup = false;
//                 continue;
//             } else {
//                 cnt++; // 不包含在之前出现过的group中，新增一个group
//                 vector<string> temp = {};
//                 temp.push_back(strs[i]);
//                 res.push_back(temp);
//             }
//         }
//         return res;
//     }

//     bool isAnagrams(string s, string t) {
//         int record[26] = {0};
//         for (auto ch : s) {
//             record[ch - 'a']++;
//         }
//         for (auto ch : t) {
//             record[ch - 'a']--;
//         }
//         for (auto i : record) {
//             if (i != 0) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> record;
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            record[str].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for (auto it = record.begin(); it != record.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = Solution().groupAnagrams(strs);
    for (auto group : res) {
        for (auto str : group) {
            cout << str << ' ';
        }
        cout << endl;
    }
    return 0;
}