#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        vector<int> next(needle.size());
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) j++;
            if (j == needle.size()) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }

    void getNext(vector<int>& next, const string s) {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            while (j > 0 && s[j] != s[i]) {
                j = next[j - 1];
            }
            if (s[j] == s[i]) j++;
            next[i] = j;
        }
    }
};

int main() {
    string haystack = "aaabfca";
    string needle = "aabf";
    cout << Solution().strStr(haystack, needle) << endl;
    return 0;
}