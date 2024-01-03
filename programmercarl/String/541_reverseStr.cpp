#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int loop = s.size() / (2 * k);
        int last = s.size() % (2 * k);
        if (last > 0) {
            int left = loop * 2 * k;
            int len = k < last ? k : last;
            int right = left + len - 1;
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        while (loop--) {
            int left = loop * 2 * k;
            int right = left + k - 1;
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};

int main() {
    string s = "abcdefg";
    int k = 2;
    cout << Solution().reverseStr(s, k) << endl;
    return 0;
}