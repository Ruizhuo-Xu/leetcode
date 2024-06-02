#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> rec(26, 0);
        for (int i = 0; i < s.size(); i++) {
            rec[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            rec[t[i] - 'a']--;
        }
        for (int i = 0; i < rec.size(); i++) {
            if (rec[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s = "abcca";
    string t = "cbcca";
    cout << Solution().isAnagram(s, t) << endl;
    return 0;
}