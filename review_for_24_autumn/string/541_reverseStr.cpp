#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 1; i <= s.size(); i++) {
            if (i % (2 * k) == 0) {
                reverse(s.begin() + i - 2 * k, s.begin() + i - k);  // reverse序列的长度=末尾-开头 比如在这里：s.begin() + i - k - (s.begin() + i - 2k) = k
                // reverse左闭右开，末尾的指针是要反转的最后一个字符的后一位
            }
        }
        int tail = s.size() % (2 * k);
        if (tail > k) {
            reverse(s.end() - tail, s.end() - tail + k);
        } else if (tail > 0) {
            reverse(s.end() - tail, s.end());
        }
        return s;
    }
};

int main() {
    string s = "krmyfshbspcgtesxnnljhfursyissjnsocgdhgfxubewllxzqhpasguvlrxtkgatzfybprfmmfithphckksnvjkcvnsqgsgosfxc";
    cout << s.size() << endl;
    cout << Solution().reverseStr(s, 20) << endl;
    return 0;
}