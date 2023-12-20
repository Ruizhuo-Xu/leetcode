#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> path;
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0);
        return res;
    }

    void backtracking(string s, int startIndex) {
        if (path.size() == 4 && startIndex == s.size()) {
            string temp;
            for (int i = 0; i < path.size() - 1; i++) {
                temp.append(path[i] + ".");
            }
            temp.append(path[path.size() - 1]);
            res.push_back(temp);
            return ;
        }
        if (path.size() != 4 && startIndex == s.size()) {
            return ;
        }
        if (path.size() == 4 && startIndex != s.size()) {
            return ;
        }
        for (int i = startIndex; i < s.size(); i++) {
            string temp = s.substr(startIndex, i - startIndex + 1);
            if (!isValid(temp)) {
                break;
            }
            path.push_back(temp);
            backtracking(s, i + 1);
            path.pop_back();
        }
    }

    bool isValid(string s) {
        if (s.size() > 1 && s[0] == '0') {
            return false;
        }
        int num = stoi(s);
        return num >= 0 && num <= 255;
    }
};

int main() {
    string s = "25525511135";
    vector<string> res = Solution().restoreIpAddresses(s);
    for (string it : res) {
        cout << it << endl;
    }
    return 0;
}