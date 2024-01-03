#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string replaceNumber(string s) {
        // 先预先给数组扩容带填充后的大小，然后在从后向前进行操作
        // 好处：不用申请新数组； 从后向前填充元素，避免了从前向后填充元素时，每次添加元素都要将添加元素之后的所有元素向后移动的问题。
        int cnt = 0; // 统计数字字符出现的次数
        for (int i = 0; i < s.size(); i++) {
            if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
                cnt++;
            }
        }
        int sOldSize = s.size();
        s.resize(s.size() + cnt * 5); // 'number'6个字符，减去本身替换的字符
        int sNewSize = s.size();
        for (int i = sOldSize - 1, j = sNewSize - 1; i >= 0; i--) {
            if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
                s[j--] = 'r';
                s[j--] = 'e';
                s[j--] = 'b';
                s[j--] = 'm';
                s[j--] = 'u';
                s[j--] = 'n';
            } else {
                s[j--] = s[i];
            }
        }
        return s;
    }
};

int main() {
    string s = "a1b2c3";
    cout << Solution().replaceNumber(s) << endl;
    return 0;
}