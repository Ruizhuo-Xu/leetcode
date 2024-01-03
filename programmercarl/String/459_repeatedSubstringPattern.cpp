#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector<int> next(s.size());
        getNext(next, s);
        int len = s.size();
        if (next[len - 1] != 0 && len % (len - next[len - 1]) == 0){ // next[len - 1] != 0说明有最长相等前后缀
            return true;
        }
        return false;
    }

    void getNext(vector<int>& next, const string s) {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < next.size(); i++) {
            while (j > 0 && s[j] != s[i]) {
                j = next[j - 1];
            }
            if (s[j] == s[i]) j++;
            next[i] = j;
        }
    }
};

int main() {
    string s = "ababab";
    cout << Solution().repeatedSubstringPattern(s) << endl;
    return 0;
}