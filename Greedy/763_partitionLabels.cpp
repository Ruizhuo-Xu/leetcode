#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution_ {
public:
    vector<int> partitionLabels(string s) {
        // 局部最优: 一旦当前子串每个字符的数量都等于s中该字符的数量(说明在其他子串中不会再出现),就记录为一个满足条件的子串
        // 全局最优: 找到尽可能多的满足条件的子串
        unordered_map<char, int> allMp; // 记录字符串s中每个字符出现的次数
        unordered_map<char, int> subMp; // 记录当前子串中每个字符出现的次数
        for (int i = 0; i < s.size(); i++) {
            allMp[s[i]]++;
        } 
        vector<int> res;
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            subMp[s[i]]++;
            unordered_map<char, int>::iterator it = subMp.begin();
            for (; it != subMp.end(); it++) {
                if (it->second != allMp[it->first]) { // 当前子串中出现的某个字符的数量和s中总的数量不相等,说明该子串后面还有该字符
                    break;
                }
            }
            if (it == subMp.end()) { // 如果循环正常结束,说明当前子串满足题目要求
                res.push_back(i - start + 1);
                start = i + 1;
                subMp.clear();
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> partitionLabels(string s) {
        // 题解代码精简
        vector<int> a(26, 0); // 26个字母直接使用数组作为哈希表
        for (int i = 0; i < s.size(); i++) {
            a[s[i] - 'a'] = i; // 记录每个字母出现的边界(最后一次出现的索引)
        }
        vector<int> res;
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, a[s[i] - 'a']); // 如果当前字符的边界大于之间记录的边界,则更新子串结束的位置
            if (i == end) { // 到达子串结束的位置
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
    for (int it : res) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}