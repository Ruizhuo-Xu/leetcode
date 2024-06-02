#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> rec(26, 0);
        for (int i = 0; i < ransomNote.size(); i++) {
            rec[ransomNote[i] - 'a']++;
        }
        for (int i = 0; i < magazine.size(); i++) {
            rec[magazine[i] - 'a']--;
        }
        for (int i = 0; i < rec.size(); i++) {
            if (rec[i] > 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s = "ab";
    string m = "aab";
    cout << Solution().canConstruct(s, m) << endl;
    return 0;
}