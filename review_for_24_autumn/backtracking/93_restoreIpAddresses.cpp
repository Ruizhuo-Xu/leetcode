#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> path;
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0);
        return res;
    }

    void backtracking(string s, int startIdx) {
        if (startIdx >= s.size()) {
            if (path.size() == 4) {
                string ip;
                for (int i = 0; i < path.size() - 1; i++) {
                    ip += (path[i] + '.');
                }
                ip += path[3];
                res.push_back(ip);
            }
            return ;
        }
        for (int i = startIdx; i < s.size() && path.size() < 4; i++) {
            if (check(s, startIdx, i)) {
                path.push_back(s.substr(startIdx, i - startIdx + 1));
                backtracking(s, i + 1);
                path.pop_back();
            } else {
                break;
            }
        }
    }

    bool check(string s, int left, int right) {
        if (right > left && s[left] == '0') { // 前导0
            return false;
        }
        int val = stoi(s.substr(left, right - left + 1));
        if (val > 255) {
            return false;
        }
        cout << "val:" << val << endl;
        return true;
    }
};

int main() {
    string s = "25525511135";
    vector<string> res = Solution().restoreIpAddresses(s);
    for (string str : res) {
        cout << str << endl;
    }
    return 0;
}