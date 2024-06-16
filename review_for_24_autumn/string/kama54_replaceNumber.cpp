#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string replaceNumber(string s) {
        // 操作字符串，优先想到双指针
        int num_cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num_cnt++;
            }
        }
        int left = s.size() - 1;  // 扩容前的边界
        s.resize(s.size() + num_cnt * 5);
        int right = s.size() - 1;  // 扩容后的新边界
        for (; left >= 0; left--) {
            if (s[left] >= '0' && s[left] <= '9') {
                s[right--] = 'r';
                s[right--] = 'e';
                s[right--] = 'b';
                s[right--] = 'm';
                s[right--] = 'u';
                s[right] = 'n';
            } else {
                s[right] = s[left];
            }
            right--;
        }
        return s;
    }
};


int main() {
    string s = "a1b2cd3j";
    cout << Solution().replaceNumber(s) << endl;
    return 0;
}
