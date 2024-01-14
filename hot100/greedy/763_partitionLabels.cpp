#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> mp(26, 0);
        for (int i = 0; i < s.size(); i++) {
            mp[s[i] - 'a'] = i; // 字符：最后出现的位置
        }
        int start = 0;
        int end = 0;
        vector<int> res;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, mp[s[i] - 'a']);
            if (i == end) {
                res.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
};

int main() {
    string s = "ababcbacadefegdehijhklij";
    vector<int> res = Solution().partitionLabels(s);
    for (int num : res) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}