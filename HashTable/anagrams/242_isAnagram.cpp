#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0}; // 使用数组作为hash table
        for (int i = 0; i < s.size(); i++) {
            record[s[i] - 'a']++; // s[i] - 'a'其实就是hash function
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s  = "anagram";
    string t = "nagaram";
    Solution so = Solution();
    cout << so.isAnagram(s, t) << endl;
}