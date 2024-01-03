#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        for (int i = 0; i < magazine.size(); i++) { // 先遍历magazin,因为magazine应该包含ransomNote
            record[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            if (record[ransomNote[i] - 'a'] == 0) { // 说明magazin中不包含ransomNote[i]
                return false;
            } else if (record[ransomNote[i] - 'a'] > 0) {
                record[ransomNote[i] - 'a']--;
            }
        }
        return true;
    }
};

int main() {
    string s = "aa";
    string t = "aab";
    Solution so = Solution();
    cout << so.canConstruct(s, t) << endl;
    return 0;
}