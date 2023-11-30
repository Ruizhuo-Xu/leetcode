#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stringParser(s);
        stringParser(t);
        cout << s << ' ' << t << endl;
        return s == t;
    }

private:
    void stringParser(string &s) {
        int slowIndex = 0;
        char target = '#';
        for (int fastIndex = 0; fastIndex < s.size(); fastIndex++) {
            if (s[fastIndex] != '#') {
                s[slowIndex++] = s[fastIndex];
            } else { // 退格
                if (slowIndex > 0) slowIndex--;
                else slowIndex = 0;
            }
        }
        s.resize(slowIndex);
    }
};

int main() {
    Solution so = Solution();
    // string s = "ab#c", t = "ad#c";
    // string s = "ab##", t = "c#d#";
    string s = "a#c", t = "b";
    cout << so.backspaceCompare(s, t) << endl;
}