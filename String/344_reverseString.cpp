#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            // char temp = s[left];
            // s[left] = s[right];
            // s[right] = temp;
            left++;
            right--;
        }
    }
};

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    Solution().reverseString(s);
    for (auto it : s) {
        cout << it << ' ';
    }
    cout << endl;
    return 0;
}